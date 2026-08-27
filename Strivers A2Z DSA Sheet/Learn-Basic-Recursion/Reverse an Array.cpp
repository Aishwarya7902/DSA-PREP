//problem :https://www.geeksforgeeks.org/problems/reverse-an-array/1






class Solution {
  public:
   
  void swap(int l,int r,vector<int> &arr){
      int temp=arr[l];
      arr[l]=arr[r];
      arr[r]=temp;
  }
  
   void recursionHelp(int l,int r,vector<int> &arr) {
       if(l>=r)return;
       
       swap(l,r,arr);
       recursionHelp(l+1,r-1,arr);
        
        
    }
    void reverseArray(vector<int> &arr) {
        // code here
        
        int n=arr.size();
        
        recursionHelp(0,n-1,arr);
    }
};
