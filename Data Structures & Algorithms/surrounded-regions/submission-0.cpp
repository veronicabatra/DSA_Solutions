class Solution {
public:
    void dfs(vector<vector<char>> &nums,vector<vector<bool>> &vis,int i,int j){
        if(i>=nums.size() || j>=nums[0].size() || i<0 || j<0 || vis[i][j] || nums[i][j]=='X') return;
        vis[i][j]=true;
        dfs(nums,vis,i+1,j);
        dfs(nums,vis,i-1,j);
        dfs(nums,vis,i,j+1);
        dfs(nums,vis,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')dfs(board,vis,i,0);
            if(board[i][m-1]=='O')dfs(board,vis,i,m-1);
        }
        for(int j=1;j<m;j++){
            if(board[0][j]=='O')dfs(board,vis,0,j);
            if(board[n-1][j]=='O')dfs(board,vis,n-1,j);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
