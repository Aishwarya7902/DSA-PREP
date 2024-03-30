PROBLEM :https://leetcode.com/problems/two-sum/description/
VIDEO : https://www.youtube.com/watch?v=TCaBnVIllrQ&list=PLpIkg8OmuX-K6A0sEPFxOSJh4_AjCGAFf

/*
  BRUTE FORCE (USING FOR LOOPS)
  TC: O(N^2)
  SC:O(1)
  */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target)return {i,j};
            }
        }
        return {};
    }
};


/*
OPTIMISATION (USING MAP)
TC:O(N)
SC:O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int required=target-curr;
            if(mp.find(required)!=mp.end()){
                return {i,mp[required]};
            }
            mp[curr]=i;
        }
        return {};
    }
};
