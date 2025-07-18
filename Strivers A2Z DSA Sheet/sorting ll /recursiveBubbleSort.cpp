/*
  Time Complexity: O(N^2)
  Space Complexity: O(N) auxiliary stack space.
*/

void recursiveBubbleSort(vector<int>& arr,int n){
        if(n==1)return; //base case
        
        // do some work
        
        for(int i=0;i<=n-2;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        
        // make recursive calls
        recursiveBubbleSort(arr,n-1);
        
    }
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        recursiveBubbleSort(arr,n);
    }


//Optimized approach (Reducing time complexity for the best case):
//Time Complexity: O(N2) for the worst and average cases and O(N) for the best case. Here, N = size of the array.

//Space Complexity: O(N) auxiliary stack space.


 void recursiveBubbleSort(vector<int>& arr,int n){
        if(n==1)return; //base case
        
        // do some work
        bool didSwap=0;
        for(int i=0;i<=n-2;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                didSwap=1;
            }
        }
        
        if(didSwap==0)return;
        // make recursive calls
        recursiveBubbleSort(arr,n-1);
        
    }
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        recursiveBubbleSort(arr,n);
    }
