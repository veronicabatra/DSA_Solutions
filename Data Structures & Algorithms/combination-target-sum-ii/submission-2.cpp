class Solution {
public:
    void fn(int i,vector<vector<int>> &ans,vector<int> &inner,vector<int> nums,int target){
        if(target==0) {
            ans.push_back(inner);
            return;
        }
        if(target<0 || i>=nums.size()) return;
        inner.push_back(nums[i]);
        fn(i+1,ans,inner,nums,target-nums[i]);
        inner.pop_back();
        int j=i;
        while(j<nums.size() && nums[j]==nums[j+1]) j++;
        fn(j+1,ans,inner,nums,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> inner;
        fn(0,ans,inner,nums,target);
        return ans;
    }
};
