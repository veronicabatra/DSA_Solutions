class Solution {
public:
    void fn(vector<vector<int>> &edges,vector<bool> &vis,int src){
        vis[src]=true;
        for(vector<int> neigh:edges){
            int u=neigh[0];
            int v=neigh[1];
            if(u==src && !vis[v]) fn(edges,vis,v);
            else if (v==src && !vis[u]) fn(edges,vis,u);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                fn(edges,vis,i);
                count++;
            }
        }
        return count;
    }
};
