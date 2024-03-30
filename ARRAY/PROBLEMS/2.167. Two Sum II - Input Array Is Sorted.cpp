
PROBLEM :https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
VIDEO :https://www.youtube.com/watch?v=gsSLay-wcaw&list=PLpIkg8OmuX-K6A0sEPFxOSJh4_AjCGAFf&index=2



/*
BRUTE FORCE (GIVES TLE)
TC:O(N^2)
SC:O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target)return {i+1,j+1};
            }
        }
        return {}; 
    }
};

/*
OPTIMISATION (TWO POINTER)
TC:O(N)
SC:(1)
  */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
        int i=0,j=n-1;
        while(i<j){
            if(nums[i]+nums[j]==target)return {i+1,j+1};
            else if(nums[i]+nums[j]<target)i++;
            else j--;
        }
        return {}; 
    }
};
