problem: https://leetcode.com/problems/permutations-ii/description/

/*
  APPROACH 1
  TC:O(N∗N!)
  SC:O(N)+O(N) //taking map and temp
*/


class Solution {
public:
    void solve(vector<int>&temp,unordered_map<int,int>&mp,vector<vector<int>>&result,int n){
        if(temp.size()==n){
            result.push_back(temp);
            return;
        }
        for(auto& [num,count]:mp){
            if(count==0)continue;
            
            temp.push_back(num); //do
            mp[num]--;
            
            solve(temp,mp,result,n); //explore

            temp.pop_back(); //backtrack
            mp[num]++;

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>result;
        vector<int>temp;
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }

        solve(temp,mp,result,n);
        return result;
    }
};

/*
APPROACH 2
  TC: O(N*N!) //n! coz of permutation and n coz we have to push temp in result which is a copy operation
  SC:O(N)
*/

class Solution {
public:
    void solve(int indx,vector<int>& nums,vector<vector<int>>&result){
        if(indx>=nums.size()){
            result.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for(int i=indx;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
                swap(nums[i],nums[indx]); //do
                solve(indx+1,nums,result); //explore
                swap(nums[i],nums[indx]); // backtrack
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>result;
        solve(0,nums,result);
        return result;
    }
};
