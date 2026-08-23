//LC 834
class Solution {
public:
    int sum=0;
    vector<int> count;
    vector<int> ans;
    int fn(vector<vector<int>> &adj,int node,int dist,int parent){
        sum+=dist;
        int currCount=1;
        for(int neigh:adj[node]){
            if(parent==neigh) continue;
            currCount+=fn(adj,neigh,dist+1,node);
        }
        count[node]=currCount;
        return currCount;
    }
    void dfs(vector<vector<int>> &adj,int n,int node,int parent){
        for(int neigh:adj[node]){
            if(neigh==parent) continue;
            ans[neigh]=ans[node]-count[neigh]+(n-count[neigh]);
            dfs(adj,n,neigh,node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v); 
            adj[v].push_back(u);
        }
        count.resize(n);
        fn(adj,0,0,-1);
        ans.resize(n);
        ans[0]=sum;
        dfs(adj,n,0,-1);
        return ans;
    }
};