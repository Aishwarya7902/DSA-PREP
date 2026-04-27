//problem :https://www.geeksforgeeks.org/problems/implement-lower-bound/1

/*
The time complexity (TC) of Binary Search is:

🔹 Best Case
O(1)
When the target element is found at the middle in the first comparison.
🔹 Average Case
O(log n)
🔹 Worst Case
O(log n)
Because the search space is halved at each step.
*/

class Solution {
    
  private:
  int binarySearch(vector<int>& arr, int target,int low,int high){
      int result=arr.size();
      while(low<=high){
          
          int mid= low + (high-low)/2;
          
          if(arr[mid]>=target){
              result=min(result,mid);
              high=mid-1;
          }
          else{
              low=mid+1;
          }
          
      }
      
      return result;
  }
  public:
  
    
    int lowerBound(vector<int>& arr, int target) {
        // code here
        
        int n=arr.size();
        
        return binarySearch(arr,target,0,n-1);
        
       
        
        
    }
};
