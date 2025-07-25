//problem :https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1

/*
self
TC : O(n+n) = O(2n) two pass solution
SC :O(1)
*/

class Solution { 
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int mx=0;
        for(int i=0;i<arr.size();i++){
            mx=max(arr[i],mx);
        }
        
        int secMax=0;
        for(int i=0;i<arr.size();i++){
             if(arr[i]>secMax && arr[i]<mx){
                 secMax=arr[i];
             }
        }
        
        if(secMax==0)return -1;
     
        return secMax;
    }
};


/*
OPTIMIZATION
TC : O(n)  one pass solution
SC :O(1)
*/

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        
        int largest=arr[0];
        int slargest=-1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>largest){
                slargest=largest;
                largest=arr[i];
            }
            
            else if(arr[i]<largest && arr[i]>slargest){
                slargest=arr[i];
            }
        }
        
        return slargest;
    }
};
