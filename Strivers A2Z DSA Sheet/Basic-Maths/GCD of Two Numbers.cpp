// problem :https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1

/*
Brute 
TC : o(min(a,b))
SC: o(1)

*/

class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        
        int ans =1;
     
        for(int i=min(a,b);i>=1;i--){
            if(a%i==0 && b%i==0){
                ans=i;
                break;
            }
        }
        
        return ans;
    }
};


/*
OPTIMAL
Euclidean Algorithm
TC : O(logϕ (min(a,b))
SC : O(1)

*/


class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        
        while(a>0 && b>0){
            if(a>b){
                a=a%b;
            }
            else{
                b=b%a;
            }
        }
        
      return a==0 ? b : a;
    }
};

