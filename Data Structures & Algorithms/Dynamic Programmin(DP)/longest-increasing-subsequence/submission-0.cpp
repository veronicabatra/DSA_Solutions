class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
        for(int i:nums) s.insert(i);
        vector<int> cp;
        for(int i:s){
            cp.push_back(i);
        }
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(cp.size()+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=cp.size();j++){
                if(nums[i-1]==cp[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][cp.size()];
    }
};
