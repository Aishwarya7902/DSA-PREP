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

/*
OPTIMIZATION
USING BINARY SEARCH

Tc : O(nlogn) + O(n * logn)
SC: O(N)

*/

class Solution {
public:
    int helperBsearch(int target,vector<int>& nums, int k,vector<long>&prefix){
        int l=0,r=target,bestMid=target;
        while(l<=r){
            int mid =  l +(r-l)/2;
            long count= target-mid+1;
            long windowSum=count*nums[target];
            long actualSum=prefix[target]-prefix[mid]+nums[mid];

            int ops=windowSum-actualSum;
            if(ops>k){
                l=mid+1;
            }
            else{
                   bestMid=mid;
                   r=mid-1;
            }



        }
        return target-bestMid+1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); // TC :nlogn
        vector<long> prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){ // TC :o(n)
            
            prefix[i]=prefix[i-1]+nums[i];
        }
        

        int result=0;
        for(int i=0;i<nums.size();i++){ // TC :(n)
            int freq=helperBsearch(i,nums,k,prefix); // TC :logn
            result=max(result,freq);
        }

        return result;
    }
};

/*
  using sliding window
//T.C : O(nlogn)
//S.C : O(1)
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int result=0;
        long currSum=0;

        int l=0;
        for(int r=0;r<nums.size();r++){
            long target=nums[r];
            currSum+= nums[r];
            long windowSum= (r-l+1)*target;
            long ops= windowSum-currSum;

            if(ops>k){
                currSum-=nums[l];
                l++;
            }

            result=max(result,r-l+1);
        }
        return result;
    }
};
