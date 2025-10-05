// problem : https://leetcode.com/problems/majority-element-ii/description/

/*
brute 
for every element ...loop and find how many times it occurs in the whole array
tc:o(n^2)
sc:o(1)
*/

/*
better
->find out freq of each element
->if freq of any element is > [n/3] put in result
->return result

TC:O(N)
SC:O(N)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();

        unordered_map<int,int>mp;

        for(auto it:nums){
            mp[it]++;
        }

        for(auto it:mp){
            if(it.second>floor(n/3))result.push_back(it.first);
        }

        return result;
    }
};
