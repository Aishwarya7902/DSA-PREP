//problem : https://leetcode.com/problems/subarray-sum-equals-k/description/

/*
brute force
tc:o(n^3)
sc:o(1)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            

            for(int j=i;j<n;j++){
                int sum=0;
                for(int l=i;l<=j;l++){
                    sum+=nums[l];
                    
                }
                if(sum==k)result++;
            }
        }
        return result;
    }
};

/*
better 
tc:o(n^2)
sc:o(1)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int sum=0;

            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k)result++;
            }
        }
        return result;
    }
};

/*
optimal 
tc:o(n)
sc:o(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefixSum;

        int sum=0,result=0;
        prefixSum[0]=1;

        for(auto it:nums){
            sum+=it;
            int remain=sum-k;
            if(prefixSum.find(remain)!=prefixSum.end()){
                result+=prefixSum[remain];
            }
            prefixSum[sum]++;
        }
        return result;
    }
};
*/
