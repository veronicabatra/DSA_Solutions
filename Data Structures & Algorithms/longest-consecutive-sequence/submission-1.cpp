class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int i=0;
        int mx=0;
        while(i<nums.size()){
            int num=nums[i];
            int curr=0;
            if(!s.count(num-1)){
                while(!s.empty()){
                if(s.count(num)){
                    curr++;
                    num++;
                }
                else break;
                }
            }
            i++;
            mx=max(mx,curr);
        }
        return mx;
    }
};
