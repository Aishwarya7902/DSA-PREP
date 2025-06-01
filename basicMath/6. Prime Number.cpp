//PROBLEM :https://www.geeksforgeeks.org/problems/prime-number2314/1
//Given a number n, determine whether it is a prime number or not.

// Approach :The key idea is if a number has only two factors  , that is 1 and the no. itself then it is a prime

class Solution {
  public:
    int totalFactors(int n){
        vector<int>temp;
        //TC :O(sqrt(n))
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                temp.push_back(i);
                if(n/i !=i)
                  temp.push_back(n/i);
            }
        }
        
        return temp.size();
    }
    bool isPrime(int n) {
        // code here
        int noOfFactors=totalFactors(n); //Time complexity depends solely on totalFactors(n) function which is O(sqrt(n))
        return  noOfFactors==2;
    }
};
