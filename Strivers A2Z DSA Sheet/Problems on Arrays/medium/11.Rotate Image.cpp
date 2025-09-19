//problem :https://leetcode.com/problems/rotate-image/description/

/*
brute force
tc:o(m*n)
sc:o(m*n)

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> newMatrix(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int newRow=j;
                int newCol=(m-1)-i;
                newMatrix[newRow][newCol]=matrix[i][j];
            }
        }
        matrix=newMatrix;
    }
};
