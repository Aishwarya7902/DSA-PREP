//PROBLEM :https://leetcode.com/problems/majority-element/description/

/*
brute force
tc:o(n^2)
sc:o(1)

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int result;
        for(int i=0;i<n;i++){
            int cnt=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]==nums[i])cnt++;
            }
            if(cnt>n/2){
                result=nums[i];
            }
        }

        return result;
    }
};
/*
better
tc:o(n)
sc:o(n)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;

        for(auto it:nums){
            mp[it]++;
        }

        for(auto it:mp){
            if(it.second>n/2)return it.first;
        }

        return 1;
          
    }
};


/*
best
Moore's Voting Algorithm
tc:o(n)
sc:o(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      //applying the algo
        int cnt=0;
        int el;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                el=nums[i];
                cnt=1;
            }
            else if(nums[i]==el)cnt++;
            else cnt--;
        }
      // u can verify the algo too if interviewer asks
      // int cnt1=0;
      //   for(int i=0;i<nums.size();i++){
      //       if(nums[i]==el)cnt1++;
      //   }
      //   if(cnt1>nums.size()/2)return el;
        return el;
    }
};
