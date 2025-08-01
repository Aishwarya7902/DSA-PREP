//problem :https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

/*
BRUTE FORCE
TC: O(N) + O(N)
SC: O(N)
*/

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        
        int n=arr.size();
        d%=n;
        vector<int> res(n);
        int indx=0;
        
        for(int j=d;j<n;j++){
            res[indx++]=arr[j];
        }
        
        for(int i=0;i<d;i++){
            res[indx++]=arr[i];
        }
        
        arr=res;
        
        
        
    }
};
