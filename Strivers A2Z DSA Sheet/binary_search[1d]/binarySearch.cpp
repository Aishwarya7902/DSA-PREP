// problem :https://leetcode.com/problems/binary-search/description/

/*
optimal
tc:o(logn).. (it will be base 2)
sc:o(1)
 */

int search(vector<int>& nums, int target) {
        int n=nums.size();

        int low=0,high=n-1;

        while(low<=high){
            int mid=low +(high-low)/2;

            if(target==nums[mid])return mid;

            else if(target > nums[mid])low=mid+1;
            else high=mid-1;
        }

        return -1;
    }
