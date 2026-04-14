class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> degree(n,0);
        vector<vector<int>> adj(n);
        for(vector<int> vec:edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
            degree[vec[0]]++;
            degree[vec[1]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(degree[i]==1) q.push(i);
        }
        int rem=n;
        while(rem>2){
            int size=q.size();
            rem=rem-size;

            while(size>0){
            int u=q.front();
            q.pop();
            size--;
            for(int i:adj[u]){
                degree[i]--;
                if(degree[i]==1) q.push(i);
            }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};