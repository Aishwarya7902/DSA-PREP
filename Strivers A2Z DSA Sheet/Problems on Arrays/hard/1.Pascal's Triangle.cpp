//problem :https://leetcode.com/problems/pascals-triangle/description/

/*
brute force

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
         result.push_back({1});
        for(int i=1;i<numRows;i++){
            
            vector<int>prev=result[i-1];

            vector<int>curr;
            for(int j=0;j<i+1;j++){
                if(j==0){
                    curr.push_back(prev[0]);
                }
                else if(j>i-1){
                    curr.push_back(prev[j-1]);
                }
                else{
                    curr.push_back(prev[j]+prev[j-1]);
                }

            }
            result.push_back(curr);
        }
        return result;
    }
};
