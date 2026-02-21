/*
Kadane's Algorithm, maximum subarray sum
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
