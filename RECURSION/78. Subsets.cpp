PROBLEM:https://leetcode.com/problems/subsets/description/

/*
  APPROACH 1
  TC: O(2^N) // at every place we have two choices
  SC: o(n) curr  + o(n) recusion stack space
  */

class Solution {
public:
    void solve(int indx,vector<int>& nums,vector<int>&curr,vector<vector<int>>&result){
        //base case
        if(indx>=nums.size()){
            result.push_back(curr);
            return;
        }

        curr.push_back(nums[indx]); //do
        solve(indx+1,nums,curr,result); //explore
        curr.pop_back(); //backtrack
         solve(indx+1,nums,curr,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>curr;

        solve(0,nums,curr,result);
        return result;
    }
};
