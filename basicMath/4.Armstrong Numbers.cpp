// PROBLEM :https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

/*
 You are given a 3-digit number n, Find whether it is an Armstrong number or not.

 An Armstrong number of three digits is a number such that the sum of the cubes of its 
 digits is equal to the number itself. 371 is an Armstrong number since 33 + 73 + 13 = 371. 

  */

/*

  Time Complexity
  O(log10n)

  Space Complexity
  O(1) constant space.

*/

class Solution {
  public:
    bool armstrongNumber(int n) {
        int x=n;
        // code here
        int total_sum=0;
        while(x){
            int digit=x%10;
            total_sum = total_sum + pow(digit,3);
            x/=10;
        }
        
        return total_sum==n ? true : false;
    }
};


