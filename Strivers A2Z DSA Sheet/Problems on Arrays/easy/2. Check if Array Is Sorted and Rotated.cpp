//PROBLEM :https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

/*
BRUTE FORCE
make all the possible rotations , i.e rotate the array by r=0,1,2,3....till n and at any point array is sorted return true...else false

tc:o(n^2)
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
