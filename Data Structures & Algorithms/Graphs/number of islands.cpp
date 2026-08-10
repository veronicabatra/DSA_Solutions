class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<char>> &grid){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || vis[i][j]) return;
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]=='1' && !vis[nx][ny]) {
                dfs(nx,ny,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]) {
                    dfs(i,j,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};