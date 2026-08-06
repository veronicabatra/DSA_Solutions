class Solution {
public:
    bool dfs(vector<vector<int>> nums,int src,vector<bool> &vis,vector<bool> &recPath){
        vis[src]=true;
        recPath[src]=true;
        for(vector<int> neigh:nums){
                int u=neigh[1];
                int v=neigh[0];
                if(u==src){
                    if(!vis[v]){
                if (dfs(nums,v,vis,recPath)) return true;
                }
            else if(recPath[v]) return true;
            }
        }
        recPath[src]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& nums) {
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(nums,i,vis,recPath)) return false;
            }
        }
        return true;
    }
};
