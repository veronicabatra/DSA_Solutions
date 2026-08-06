class Solution {
public:
    bool isCycle(vector<vector<int>> &adj,vector<bool> &vis,int src,vector<bool> &recPath,stack<int> &st){
        vis[src]=true;
        recPath[src]=true;
        for(int v:adj[src]){
            if(!vis[v]) {
                if(isCycle(adj,vis,v,recPath,st)) return true;
            }else {
                if(recPath[v]) return true;
            }
        }
        recPath[src]=false;
        st.push(src);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& nums) {
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for(vector<int> p:nums){
            adj[p[1]].push_back(p[0]);
        }
        stack<int> st;
        vector<bool> recPath(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(adj,vis,i,recPath,st)) return {};
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    return ans;
    }
};
