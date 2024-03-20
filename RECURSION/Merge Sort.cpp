PROBLEM :https://www.geeksforgeeks.org/problems/merge-sort/1
/*
  TC: O(nlogn)
  SC: o(logn) // recursive stack space
*/

class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int n1=m-l+1;
         int n2=r-m;
         
         int L[n1],R[n2];
         
         int k=l;
         //putting left part in left array;
         
         for(int i=0;i<n1;i++){
             L[i]=arr[k];
             k++;
         }
         
         // putting right part in right array
         
         for(int i=0;i<n2;i++){
             R[i]=arr[k];
             k++;
         }
         
         //merge them in Arr
         
         int i=0;
         int j=0;
         k=l;
         
         while(i<n1 && j<n2){
             if(L[i]<=R[j]){
                 arr[k]=L[i];
                 i++;
             }
             else{
                  arr[k]=R[j];
                  j++;
             }
             k++;
         }
         
         while(i<n1){
             arr[k]=L[i];
             i++;
             k++;
         }
         
         while(j<n2){
             arr[k]=R[j];
             j++;
             k++;
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)return;
        int mid= l+(r-l)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
};
