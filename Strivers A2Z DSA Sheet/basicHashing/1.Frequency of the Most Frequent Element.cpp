// PROBLEM :https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

/*
   BRUTE FORCE  (Gives TLE)
   tc: O(nlogn) + o(n^2)
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int max_freq=1;
        for(int i=1;i<nums.size();i++){
            int j=i-1,K=k,freq=1;

            while(K && j>=0){
                if(nums[i]-nums[j]<=K){
                    K-=nums[i]-nums[j];
                    freq++;
                    max_freq=max(max_freq,freq);
                }
                else
                   break;
                j--;
            }
        }

        return max_freq;
    }
};
