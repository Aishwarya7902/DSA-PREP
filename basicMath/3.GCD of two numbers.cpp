// Problem : https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1

/*
BRUTE FORCE
find the GCD (greatest common divisor) by checking all numbers from 2 up to the smaller of a and b, keeping track of the largest one that divides both.

Time Complexity
You iterate from 2 to min(a, b) → O(min(a, b))
🛠 Space Complexity
O(1)

*/

class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        int min= 0;
        int result=1;
        // finding out minimum of a,b
        if(a>b){
            min=b;
        }
        
        else{
            min=a;
        }
        
        for(int i=2;i<=min;i++){
            if( a%i==0 && b%i==0){
                result=i;
            }
        }
        return result;
    }
};


/*

  OPTIMISATION USING
  Euclidean algorithm
  gcd(a,b)=gcd(b,a%b)  untill b completly divides a 
  For clear understanding  see the video : https://www.youtube.com/watch?v=utZcJ0leZ_g&t=313s

  Time Complexity: O(log min(a, b))
  Auxiliary Space: O(log (min(a,b)))
*/


class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        if(a%b==0)return b;
        return gcd(b,a%b);
    }
};


