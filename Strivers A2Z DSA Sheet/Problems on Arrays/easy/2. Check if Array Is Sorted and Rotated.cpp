//PROBLEM :https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

/*
BRUTE FORCE
make all the possible rotations , i.e rotate the array by r=0,1,2,3....till n and at any point array is sorted return true...else false

tc:o(n*(n+n))  = O(n*2n)
sc:o(n)
*/

class Solution {
public:
    bool isSorted(vector<int>&sorted){
         for(int i=0;i<sorted.size()-1;i++){
            if(sorted[i]>sorted[i+1])return false;
         }

         return true;
    }
    bool check(vector<int>& nums) {
        int n=nums.size();

        for(int r=0;r<n;r++){
            vector<int>sorted(n);
            int indx=0;
            for(int i=r;i<n;i++){
                sorted[indx++]=nums[i];
            }
            for(int i=0;i<r;i++){
                sorted[indx++]=nums[i];
            }

            if(isSorted(sorted))return true;
        }

        return false;
    }
};

/*
OPTIMIZATION
TC: O(n*n)
SC: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());

        for(int r=0;r<n;r++){
            bool isSorted=true;
            for(int i=0;i<n;i++){
                if(sorted[i]!=nums[(i+r)%n]){
                   isSorted=false;
                }
            }

            if(isSorted)return true;
        }
        return false;
    }
};

/*
BEST APPROACH
TC:O(N)
SC:O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int peak=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n])peak++;
           
        }

        return peak>1 ? false :true;
    }
};
