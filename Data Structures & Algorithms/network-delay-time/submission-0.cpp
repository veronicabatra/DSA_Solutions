class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){  //adjacency list that stores {v,wt} 
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //pq->{dist,node}
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        while(!pq.empty()){
            int u=pq.top().second;
            int cost=pq.top().first;
            pq.pop();
            vector<pair<int,int>> neigh=adj[u];
            for(pair<int,int> p:neigh){
                if(dist[p.first]>cost+p.second){
                    dist[p.first]=cost+p.second;
                    pq.push({dist[p.first],p.first});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
