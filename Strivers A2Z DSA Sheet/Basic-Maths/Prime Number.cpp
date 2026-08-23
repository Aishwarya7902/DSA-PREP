//problem : https://www.geeksforgeeks.org/problems/prime-number2314/1


/*
BRUTE : 
TC : O(n)
SC : O(1)

*/

class Solution {
  public:
    bool isPrime(int n) {
        // code here
        int count =0;
        
        for(int i=1;i<=n;i++){
            if(n%i==0)count++;
        }
        
        return count==2;
    }
};




/*
BETTER 
TC : O(sqrt(n))
SC : O(1)

*/

class Solution {
  public:
    bool isPrime(int n) {
        // code here
        int count =0;
        
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                count++;
                if(n/i!=i)count++;
            }
        }
        
        return count==2;
    }
};


