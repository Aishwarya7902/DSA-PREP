//PROBLEM :https://leetcode.com/problems/max-consecutive-ones/description/

/*
tc:o(n)
sc:o(1)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int result=0,curr=0;
       for(int i=0;i<nums.size();i++){
             if(nums[i]==1)curr++;
             else{
                result=max(result,curr);
                curr=0;
             }
       } 

       result=max(result,curr);
       return result;
    }
};
