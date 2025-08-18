//https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1


/*
brute force
tc:o(n^2)
sc:o(1)
*/

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int result=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==k){
                    result=max(result,j-i+1);
                }
            }
        }
        
        return result;
    }
};


