class Solution {
public:
    bool cycle(int src,vector<vector<int>> nums,vector<bool> &vis,vector<bool> &recPath){
        vis[src]=true;
        recPath[src]=true;
        for(vector<int> neigh:nums){
            int v=neigh[0];
            int u=neigh[1];
            if(u==src){
                if(!vis[v]) {
                    if(cycle(v,nums,vis,recPath)) return true;
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
                if(cycle(i,nums,vis,recPath)) return false;
            }
        }
        return true;
    }
};
