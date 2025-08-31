//problem 


/*
brute force
tc:o(n^2)
sc:o(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int result=INT_MIN;
       int n=nums.size();

       for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            result=max(result,sum);
        }
       } 

       return result;
    }
};


/*
best 
Kadane's Algorithm
TC:o(n)
SC:o(1)
*/

class Solution {
public:
    // kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        long long result=LONG_MIN;
        long long sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            result=max(result,sum);
            if(sum<0)sum=0;
            
               
            
        }
        return result;
    }
};
