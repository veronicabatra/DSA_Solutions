class Solution {
public:
    void per(vector<int> &nums,vector<vector<int>> &ans,vector<int> subset){
        if(nums.size()==0) {
            ans.push_back(subset);
            return;
        }
        vector<int> num(nums.begin()+1,nums.end());
        vector<int> sub=subset;
        sub.push_back(nums[0]);
        per(num,ans,sub);
        per(num,ans,subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        if(nums.size()==0) return ans;
        per(nums,ans,subset);
        return ans;
    }
};
