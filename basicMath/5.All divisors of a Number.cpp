//PROBLEM : https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1
//Given an integer N, print all the divisors of N in the ascending order.
 


/*
BRUTE FORCE
TC: O(N)
SC:O(1)
*/

class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        
        for(int i=1;i<=n;i++){
            if(n%i==0){
                cout<<i<<" ";
            }
        }
    }
};

