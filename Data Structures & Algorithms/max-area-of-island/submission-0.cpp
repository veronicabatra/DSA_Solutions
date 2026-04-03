class Solution {
public:
    void dfs(int i,int j,int &curr,vector<vector<bool>> &vis,vector<vector<int>> &grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return;
        if(vis[i][j]) return;
        vis[i][j]=true;
        curr++;
        dfs(i+1,j,curr,vis,grid);
        dfs(i-1,j,curr,vis,grid);
        dfs(i,j+1,curr,vis,grid);
        dfs(i,j-1,curr,vis,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int curr=0;
                    dfs(i,j,curr,vis,grid);
                    area=max(area,curr);
                }
            }
        }
        return area;
    }
};
