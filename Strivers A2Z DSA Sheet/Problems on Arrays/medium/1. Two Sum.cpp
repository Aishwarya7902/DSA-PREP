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

/*
TWO POINTER SOLUTION
best solution (only if ques says return true / false if two numbers add up to target ...not asking for index only then this solution is valid
tc:o(nlogn) as we are sorting
sc:o(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        int n=nums.size();
        sort(begin(nums),end(nums));
        int left=0,right=n-1;
        while(left<right){
            int sum=nums[left]+nums[right]
            if(sum==target){
                result.push_back(left);
                result.push_back(right);
                break;
            }
            else if(sum<target)left++;
            else right--;
        }
        return result;
    }
};
