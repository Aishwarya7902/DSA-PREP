//problem :https://www.geeksforgeeks.org/problems/merge-sort/1

/*

Intuition: 
1.Break the problem of “sorting an entire array” into two smaller, identical subproblems: “sort the left half” and “sort the right half.”
2. Conquer (Merge)
Merging two sorted lists is the heart of Merge Sort.

*/

/*
TIME COMPLEXITY : O(n*logn) // base 2
SPACE COMPLEXITY :O(1)
*/


class Solution {
  public:
  
    void merge(vector<int>& arr, int low,int mid, int high){
        
        int left=low;
        int right=mid+1;
        
        vector<int>temp;
        
        while(left<=mid && right <=high){
            
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left<=mid){
             temp.push_back(arr[left]);
             left++;
        }
        
        while(right<=high){
             temp.push_back(arr[right]);
             right++;
        }
        
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        
        if(l>=r)return;
        
        int mid = l + (r-l)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
        
        
    }
};
