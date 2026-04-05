class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=points.size();
        vector<bool> vis(n,false);
        int count=0;
        int cost=0;
        pq.push({0,0}); //{dist,node}
        while(!pq.empty()){
            int u=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            if(!vis[u]){
                vis[u]=true;
                count++;
                cost+=dist;
                if(count==n) return cost;
            }else continue;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                int x1=points[u][0];
                int y1=points[u][1];
                int x2=points[i][0];
                int y2=points[i][1];
                int distance=abs(x1-x2)+abs(y1-y2);
                pq.push({distance,i});
                }
            }
        }
        return cost;
    }
};
