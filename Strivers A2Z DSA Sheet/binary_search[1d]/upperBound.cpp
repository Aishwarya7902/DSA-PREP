//problem :https://www.geeksforgeeks.org/problems/implement-upper-bound/1

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
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        
        
        int n=arr.size();
        int result=n;
        
        int low =0,high=n-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]>target){
               result=min(result,mid);
               high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return result;
    }
};
