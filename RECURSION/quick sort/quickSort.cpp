/*
    TIME COMPLEXITY
    worst case :o(n^2) //similar to merge sort
    Avg case : o(nlogn) //similar to merge sort

    NOTE : quick sort is preferred over merge sort coz it does not take any extra array
*/
  
    

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low>=high)return;
        
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       
       int pivot=arr[high];
       
       int pi=low-1;
       for(int j=low;j<high;j++){
           if(arr[j]<pivot){
               pi++;
               swap(arr[j],arr[pi]);
               
           }
       }
       pi++
       swap(arr[pi],arr[high]);
       return pi;
    }
};
