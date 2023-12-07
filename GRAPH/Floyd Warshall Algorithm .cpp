PROBLEM:https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=DzfmJoFq1pc&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=32

/*
  TC:O(N^3)
  SC:O(1)
  */


class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=100000;
	            }
	        }
	    }
	    
	    for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
	        }
	    }
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==100000){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	   
	}
};
