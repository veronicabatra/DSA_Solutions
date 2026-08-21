class Solution {
public:
    int fn(int sum,vector<int> &buckets,vector<int> &nums,int idx){
        if(idx==nums.size()) return true;
        for(int i=0;i<buckets.size();i++){
            if(nums[idx]+buckets[i]<=sum){
                buckets[i]+=nums[idx];
                if(fn(sum,buckets,nums,idx+1)) return true;
                buckets[i]-=nums[idx];
            }
            if(buckets[i]==0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int x:nums) sum+=x;
        if(sum%k!=0) return false;
        sum/=k; //sum of every subset 
        vector<int> buckets(k,0);
        return fn(sum,buckets,nums,0);
    }
};