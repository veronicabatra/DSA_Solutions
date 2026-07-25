// Intuition
// We would get the max sum when we combine the greater elements and then sum them . Simply sorting the whole array wont work because what if the 0th requests are not there and we have the max element at 0th index .
// So we must sort in a different way and then solve our problem in a single loop

// Approach
// We want the frequency of all the elements that have appeared till now
// so maintain a freq vector
// for each request : {st,end}
// freq[st]+=1;
// freq[end+1]-=1;
// which means that from st to end we have requests to be proocessed
// and then to calculate the total requests at a particular index , we would do freq[i]+=freq[i-1] ina seaprate loop (prefix sum)

// Complexity
// Time complexity:
// first there is loop to calculate freq of req.size() (req size and nums size is same ,its given)

// then a loop for maintaining running sum running n times

// then again a loop running n times
// So overll Time Complexity i O(3N)~O(N)

// Space complexity:
// we have used a freq vector of size n
// So overall SC: O(N)


class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        //maintain freq of numbers 
        int n=nums.size();
        vector<int> freq(n,0);
        for(int i=0;i<req.size();i++){
            int st=req[i][0];
            int end=req[i][1];
            freq[st]+=1;
            if(end+1<n) freq[end+1]-=1;
        }

        //maintain a running sum
        for(int i=1;i<freq.size();i++){
            freq[i]+=freq[i-1];
        }
        //sort both the arrays
        sort(nums.begin(),nums.end());
        sort(freq.begin(),freq.end());
        int mod=1e9+7;
        long long sum=0;
        for(int i=0;i<freq.size();i++){
            long long a=nums[i];
            long long b=freq[i];
            sum=(sum+a*b)%mod;
        }
        return sum;
    }
};