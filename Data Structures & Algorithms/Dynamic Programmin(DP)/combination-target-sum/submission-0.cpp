class Solution {
public:
    void fn(vector<vector<int>> &ans,vector<int> curr,vector<int> &nums,int target,int i){
        if(target==0) {
            ans.push_back(curr);
            return;
        }
        if(target<0 || i==nums.size()) return;
        curr.push_back(nums[i]);
        fn(ans,curr,nums,target-nums[i],i);
        curr.pop_back();
        fn(ans,curr,nums,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        fn(ans,curr,nums,target,0);
        return ans;
    }
};
