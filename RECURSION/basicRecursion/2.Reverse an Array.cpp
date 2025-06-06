//You are given an array of integers arr[]. Your task is to reverse the given array.

/*
BRUTE FORCE
TC:O(N)
SC:O(N)
*/

class Solution {
  public:
    void helperreverseArray(int i,int n,vector<int> &res,vector<int> &arr){
        if(i==n)return;
        helperreverseArray(i+1,n,res,arr);
        res.push_back(arr[i]);
    }
    void reverseArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> res;
        helperreverseArray(0,n,res,arr);
        arr=res;
        
    }
};



// What if you are not allowed to use any extra space ? i.e you  have to it inplace , how would u solve it
//tc:o(n/2)
//sc:o(1)
class Solution {
  public:
    
    void reverseArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0,j=n-1;
        while(i<=j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    
};

// using recursion

class Solution {
  public:
    
    void helperReverse(vector<int> &arr,int l,int r){
            if(l>=r)return;
            
            // swap elements at l and r
            int temp=arr[l];
            arr[l]=arr[r];
            arr[r]=temp;
            
            helperReverse(arr,l+1,r-1);
            
        
        
    }
    
    void reverseArray(vector<int> &arr) {
        // code here
       int n=arr.size();
       helperReverse(arr,0,n-1);
    }
    
};

