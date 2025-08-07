//problem :https://leetcode.com/problems/move-zeroes/description/

/*
 brute force
 take an extra array of n size and initialize all elements with 0
 traverse through nums and if any element is apart from 0 put it in ans vector starting from the 1st place

 TC: O(N)
 SC: O(N)

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);

        int k=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                ans[k++]=nums[i];
            }
        }
        nums=ans;
    }
};


/*
beter
TC: O(N)
 SC: O(1)
*/

class Solution {
public:
    void swap(vector<int>& nums,int i,int j){
        int  temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return;

        int i=0,j=1;
        while(i<n && j<n){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums,i,j);
                i++;
                j++;
            }
            else if(nums[i]==0 && nums[j]==0)j++;
            else {
               i++;
               j++; 

            };
        }
    }
};
