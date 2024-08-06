problem: https://leetcode.com/problems/permutations-ii/description/
VIDEO :https://www.youtube.com/watch?v=Vd2YizhbN74&list=PLpIkg8OmuX-IBcXsfITH5ql0Lqci1MYPM&index=16
/*
  APPROACH 1
  TC:O(N∗N!)
  SC:
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
