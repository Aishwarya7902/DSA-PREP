/*
Time Complexity: O(N2), (where N = size of the array), for the worst, and average cases.
Space Complexity: O(N) auxiliary stack space.

Best Case Time Complexity:  O(N)
The best case occurs if the given array is already sorted.

*/


void recursiveInsertionSort(vector<int>& arr,int i,int n){
        if(i==n)return;
        
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
        recursiveInsertionSort(arr,i+1,n);
        
    }
    void insertionSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        recursiveInsertionSort(arr,0,n);
    }
