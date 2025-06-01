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


/*
OPTIMISATION
TC:O(sqrt(n))
SC:O(1)
*/

class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int>temp;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
               temp.push_back(i);
                if(n/i !=i){
                   temp.push_back(n/i);
                }
            }
        }
        //since we have to print in ascending order
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            cout<<temp[i]<<" ";
        }
    }
};

