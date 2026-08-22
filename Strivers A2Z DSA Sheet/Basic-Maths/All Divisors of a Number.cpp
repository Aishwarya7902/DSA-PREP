//  https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1

/*
Brute (Giving TLE) 
TC : O(n)
SC : O(1)

*/


class Solution {
  public:
    vector<int> getDivisors(int n) {
        // code here
        
        
        vector<int>result;
        
        for(int i=1;i<=n;i++){
            
            if(n%i==0)result.push_back(i);
        }
        
        return result;
        
    }
};

/*

optimal
TC : O(sqrt(n) + mlogm ) // where m is the no of divisor
SC : O(1)
*/

class Solution {
 
  public:
  
   
    vector<int> getDivisors(int n) {
        // code here
        if(n==1) return {1};
        
       
        vector<int>result;
        
        for(int i=1;i*i<=n;i++){
            
            if(n%i==0){
            
            result.push_back(i);
            if(n/i!=i)result.push_back(n/i);
             
            }
        }
        sort(begin(result),end(result));
        
        return result;
        
    }
};
