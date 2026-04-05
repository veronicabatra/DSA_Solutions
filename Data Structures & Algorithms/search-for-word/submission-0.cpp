class Solution {
public:
    bool fn(vector<vector<char>> &board,vector<vector<bool>> &vis,int i,int j,int idx,string word){
        if(idx==word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j] || board[i][j]!=word[idx]) return false;
        vis[i][j]=true;
        if(fn(board,vis,i+1,j,idx+1,word) ||
            fn(board,vis,i-1,j,idx+1,word) ||
            fn(board,vis,i,j+1,idx+1,word) ||
            fn(board,vis,i,j-1,idx+1,word) ) return true;
            vis[i][j]=false;
            return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && !vis[i][j]) {
                   
                    if(fn(board,vis,i,j,0,word)) return true;
                }
            }
        }
        return false;
    }
};
