//PROBLEM :https://leetcode.com/problems/rotate-array/description/


/*
brute force
traverse in the array , take ith index and send it to (i+k)%size index
TC:O(N)
SC:O(N)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>curr(n);

        for(int i=0;i<n;i++){
            curr[(i+k)%n]=nums[i];
        }
        nums=curr;
    }
};
