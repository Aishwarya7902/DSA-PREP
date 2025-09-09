// problem:https://leetcode.com/problems/set-matrix-zeroes/description/

/*
brute force
tc:O((m*n)*n + (m*n)m)
sc:O(m*n)
*/

class Solution {
public:
    void setZeroHelper(vector<vector<int>>& curr,int row,int col,int rowSize,int colSize){
        //filling up the row

        for(int i=0;i<colSize;i++){
               curr[row][i]=0;
        }

        //filling up the col

        for(int i=0;i<rowSize;i++){
               curr[i][col]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> curr=matrix;
        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if(matrix[i][j]==0)
                  setZeroHelper(curr,i,j,m,n);
            }
        }
        matrix=curr;
    }
};
