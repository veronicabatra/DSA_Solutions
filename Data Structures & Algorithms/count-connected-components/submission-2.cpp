class Solution {
public:
    void fn(vector<vector<int>> &adj,vector<bool> &vis,int src){
        vis[src]=true;
        vector<int> neigh=adj[src];
        for(int v:neigh){
            if(!vis[v]) fn(adj,vis,v);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                fn(adj,vis,i);
                count++;
            }
        }
        return count;
    }
};
