//https://www.geeksforgeeks.org/problems/factorial5739/1


/*
TC :O(n)
SC :O(n) auxiliary stack space

*/

class Solution {
  public:
    int factorial(int n) {
        // code here
        if(n==0)return 1;
        
        return n*factorial(n-1);
    }
};
