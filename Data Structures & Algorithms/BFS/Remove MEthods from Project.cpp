Leetcode 3310 
// Easy BFS approach
// C++
// Intuition
// We can think of the methods as nodes of a directed graph.

// If method a calls method b, we add an edge:

// a -> b

// Approach
// Step 1: Find all suspicious methods

// We start from method k, because k is the suspicious method.

// Using BFS, we visit every method that can be reached from k.

// All visited methods are considered suspicious.

// For example:

// k -> A -> B -> C

// Then k, A, B, and C are all suspicious.

// Step 2: Check if we are allowed to remove them

// We cannot remove the suspicious methods if there is a non-suspicious method that calls a suspicious method.

// For every invocation u -> v, we check:

// if (!vis[u] && vis[v])

// Here:

// u is non-suspicious
// v is suspicious

// This means some normal method depends on a suspicious method, so we cannot remove the suspicious methods.

// In that case, we return all methods.

// Step 3: Remove suspicious methods

// If no non-suspicious method calls a suspicious method, then all suspicious methods can be removed.

// So we simply return all methods where:

// vis[i] == false

// Complexity
// Building the graph takes O(m), where m is the number of invocations.

// BFS takes O(n + m).

// The final check also takes O(m).

// Time complexity: O(n+m)

// Space complexity: O(n+m)

// Code
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& nums) {
        vector<int> ans;
        vector<int> all;
        for(int i=0;i<n;i++) all.push_back(i);

        vector<vector<int>> adj(n);
        for(vector<int> edges:nums){
            int a=edges[0];
            int b=edges[1];
            adj[a].push_back(b);
        }
        vector<bool> vis(n,false);
        vis[k]=true;
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:adj[u]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        for(vector<int> edges:nums){
            int u=edges[0];
            int v=edges[1];
            if(!vis[u] && vis[v]){
                return all;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};