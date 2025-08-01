//problem :https://www.naukri.com/code360/problems/left-rotate-an-array-by-one_5026278?leftPanelTabValue=PROBLEM

/*
BRUTE FORCE
TC:O(N)
SC:O(N)
*/

#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    
    vector<int>result(n);
    result[n-1]=arr[0];
    for(int i=1;i<n;i++){
        result[i-1]=arr[i];
    }

    
     return result;
    
}


/*
BETTER 
TC:O(N)
SC:O(1)
*/

#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    
    
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }

     arr[n-1]=temp;
     return arr;
    
}
