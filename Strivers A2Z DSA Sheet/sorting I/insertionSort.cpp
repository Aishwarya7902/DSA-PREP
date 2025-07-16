//PROBLEM : https://www.geeksforgeeks.org/problems/insertion-sort/1

// Intuition : take an element , insert it at it's correct position in the sorted array (leftwards)

/*
 Time Complexity
 Best (already sorted)	:O(n)
 Average/Worst :O(n^2)
 Space Complexity : o(1)

*/

void insertionSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<n;i++){
            int j=i;
            while(j>0 && arr[j-1]>arr[j]){
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                j--;
                
            }
        }
        
    }
