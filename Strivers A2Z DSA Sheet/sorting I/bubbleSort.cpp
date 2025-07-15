//problem : https://www.geeksforgeeks.org/problems/bubble-sort/1

/*
Core Intuition (“Bubble” Mechanism)
Pass over the array: Compare adjacent pairs (A[j], A[j+1]).

Swap if out‐of‐order: If A[j] > A[j+1], swap them.

Largest element “bubbles up”: After one full pass, the maximum of the subarray drifts to the rightmost position.

Repeat on the unsorted prefix: Next pass, we ignore the last (already‐placed) element and bubble the next largest, and so on.
*/



/*
 TIME COMPLEXITY ANALYSIS
 Best Case (already sorted):
 First pass makes n−1 comparisons, sees no swaps → we exit early → O(n).

 Average Case:
 Random data will need about half the possible swaps and comparisons → Θ(n²).

 Worst Case (reverse sorted):
 Every pair is out‐of‐order every time → ≈n(n−1)/2 comparisons and swaps → Θ(n²).


Space Complexity: O(1) extra space (in‑place).


*/

void bubbleSort(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        bool swap=false;
        
        for(int i=n-1;i>=0;i--){
            
            for(int j=0;j<=i-1;j++){
                if(arr[j]>arr[j+1]){ //swap
                    int temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                    swap=true;
                    
                }
            }
            
            if(!swap)break;
        }
        
    }
