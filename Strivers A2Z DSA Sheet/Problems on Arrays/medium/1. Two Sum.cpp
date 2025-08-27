//problem :https://leetcode.com/problems/two-sum/description/

/*
brute force
tc:o(n^2)
sc:o(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    result.push_back(i);
                    result.push_back(j);

                
                }
            }
        }
        return result;
    }
};

/*
OPTIMIZATION
TC: o(2n)
SC:o(n) since we used a extra map

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>result;

        for(int i=0;i<nums.size();i++){
            int current=nums[i];
            int remaining=target-current;

            if(mp.find(remaining)!=mp.end()){
                   result.push_back(i);
                   result.push_back(mp[remaining]);
                   break;
            }

            mp[nums[i]]=i;

        }

        return result;
    }
};
