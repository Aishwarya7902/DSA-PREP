// problem :https://www.geeksforgeeks.org/problems/square-root/1

/*
brute 
tc:o(n)
sc:o(1)

*/
class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        
        
        for(int i=1;i<=n;i++){
            if(i*i==n)return i;
            
            if(i*i>n)return i-1;
        }
        
         
        
       return 0; 
    }
};
/*
OPTIMAL (USING BINARY SEARCH) 
tc:o(logn)
sc:o(1)

*/

class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int ans=1;
        
        int low=1,high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(mid*mid<=n){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};

