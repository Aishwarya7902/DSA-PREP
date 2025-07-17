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
  
    void merge(vector<int>& arr, int l,int mid, int r){
        vector<int>temp(r-l+1);
        
        int left=l,right=mid+1,k=0;
        while(left<=mid && right<=r){
            if(arr[left]<=arr[right]){
                temp[k]=arr[left];
                left++;
            }
            else{
                temp[k]=arr[right];
                right++;
            }
            
            k++;
        }
        
        while(left<=mid){
                temp[k]=arr[left];
                left++; 
                k++;
        }
        
        while(right<=r){
                temp[k]=arr[right];
                right++; 
                k++;
        }
        
        for(int i=l;i<=r;i++){
            arr[i]=temp[i-l];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r)return;
        
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};
