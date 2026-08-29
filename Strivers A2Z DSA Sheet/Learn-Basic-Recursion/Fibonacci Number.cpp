// problem : https://leetcode.com/problems/fibonacci-number/description/

/*

TC : O( 2^n ) exponential
Space = O(n)   at most n recursive calls are sitting on the stack.

*/
class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;

        return fib(n-1)+fib(n-2);
    }
};

