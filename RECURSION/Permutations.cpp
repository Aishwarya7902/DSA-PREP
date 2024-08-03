PROBLEM:https://leetcode.com/problems/permutations/description/


/*
  SELF TRY
  TC:O(N!)
  SC:
*/

class Solution {
public:
    void solve(vector<int>& nums,int indx,vector<int>&curr,vector<vector<int>>&result,unordered_set<int>&st){
        int n=nums.size();
        if(indx>=n){
            result.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++)
        {   if(st.find(nums[i])==st.end()){
              curr.push_back(nums[i]);
              st.insert(nums[i]);
              solve(nums,indx+1,curr,result,st);
              curr.pop_back();
              st.erase(nums[i]);
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>curr;
        unordered_set<int>st;
        vector<vector<int>>result;
        solve(nums,0,curr,result,st);

        return result;
    }
};

/*
METHOD 2
  TC:
  SC:
  */

class Solution {
public:
    void solve(vector<int>& nums,int indx,vector<vector<int>>&result){
        int n=nums.size();
        if(indx==n){
            result.push_back(nums);
            return;
        }
        for(int i=indx;i<n;i++)
        {   
              swap(nums[i],nums[indx]);
              solve(nums,indx+1,result);
              swap(nums[i],nums[indx]);

            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>result;
        solve(nums,0,result);

        return result;
    }
};
