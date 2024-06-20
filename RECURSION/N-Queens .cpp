PROBLEM : https://shorturl.at/K7lmb

VIDEO: https://shorturl.at/TNGND

/*
  APPROACH 1
  TC: N*(N-3)*(N-5).........
     approax O(N!)
  SC: O(1) //
      O(N) // stack space

*/

class Solution {
public:
    bool isValid(vector<string>&board,int row,int col){
        //check upward
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q')return false;
        }
        //check upward left

        for(int i=row-1,j=col-1;i>=0 && j>=0 ;i--,j--){
            if(board[i][j]=='Q')return false;
        }
      //check upward right
         for(int i=row-1,j=col+1;i>=0 && j<board.size() ;i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
    void solve(vector<string>&board,int row,vector<vector<string>>&result){
        int n=board.size();
        if(row>=n){
            result.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(board,row,col)){
                board[row][col]='Q';
                solve(board,row+1,result);//explore
                //backtrack
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>board(n,string(n,'.'));
        solve(board,0,result);
        return result;
    }
};


