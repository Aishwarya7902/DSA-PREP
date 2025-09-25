//problem :https://leetcode.com/problems/spiral-matrix/description/

/*
tc:o(m*n)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n=matrix[0].size();

        int left=0,right=n-1;
        int top=0,bottom=m-1;
        vector<int> ans;

        while(top<=bottom &&  left<=right){
            // moving to right

        for(int i=left;i<=right;i++){
            int curr=matrix[top][i];
            ans.push_back(curr);
        }

        top++;

        //moving towards bottom

        for(int i=top;i<=bottom;i++){
            int curr=matrix[i][right];
            ans.push_back(curr);
        }

        right--;

        //moving towards left

        if(top<=bottom){
            for(int i=right;i>=left;i--){
            int curr =matrix[bottom][i];
            ans.push_back(curr);
        }
        bottom--;
        }

        //moving towards up

        if(left<=right){
            for(int i=bottom;i>=top;i--){
            int curr=matrix[i][left];
            ans.push_back(curr);
        }
        left++;
        }

        }

        return ans;
    }
};
