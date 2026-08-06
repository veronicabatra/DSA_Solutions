class Solution {
public:
    bool valid(vector<string> &board,int row,int col){
        int n=board.size();
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q') return false;
        }
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    } 
    void queens(vector<vector<string>> &ans,vector<string> &inner,int n,int row){      
        if(row==n){  
            ans.push_back({inner});
            return;
        }
        for(int col=0;col<n;col++){
                if(valid(inner,row,col)){
                    inner[row][col]='Q';
                    queens(ans,inner,n,row+1);
                    inner[row][col]='.';
                }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> inner(n,string(n,'.'));
        queens(ans,inner,n,0);
        return ans;
    }
};
