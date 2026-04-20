class Solution {
public:
    bool valid(int row,int col,vector<string> &board){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q') return false;
        }
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void queens(int &ans,vector<string> &board,int n,int row){
        if(row==n){
            ans++;
            return;
        }
        for(int col=0;col<n;col++){
            if(valid(row,col,board)){
                board[row][col]='Q';
                queens(ans,board,n,row+1);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<string> board(n,string(n,'.'));
        queens(ans,board,n,0);
        return ans;
    }
};