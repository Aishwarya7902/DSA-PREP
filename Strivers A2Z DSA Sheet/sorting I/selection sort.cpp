// problem :https://www.geeksforgeeks.org/problems/selection-sort/1

/*
INTUTION BEHIND
for i in 0 to n-2:               # i marks the boundary between sorted and unsorted
    minIndex = i                # assume the first unsorted element is the smallest
    for j in i to n-1:        # scan the rest of unsorted region
        if A[j] < A[minIndex]:
            minIndex = j        # found new minimum—remember its index
    swap A[i] and A[minIndex]   # put the smallest found at the front of unsorted



*/


/*
Time and Space Complexity
Best/Worst/Average Case: Always 𝑂(𝑛²) comparisons.
Auxiliary Space	𝑂(1)
*/


/*
When and Why You’d Use It
Tiny Arrays: For very small n (say, n < 20), simplicity can outweigh more complex algorithms.

Memory‑Constrained Environments: When 𝑂(1) space is critical.

In competitive programming, you’ll almost never write selection sort in a contest—built‑ins (like C++’s std::sort) are far faster.
  */


void selectionSort(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        for(int i=0;i<n-1;i++){
            
            int mini=i;
             
             // find minimum element of the selected unsorted array
            for(int j=i;j<n;j++){
                if(arr[j]<arr[mini]){
                    mini=j;
                }
            }
            
            // swap the min elem of this window at the starting point
            
            int temp=arr[i];
            arr[i]=arr[mini];
            arr[mini]=temp;
        }
        
    }
