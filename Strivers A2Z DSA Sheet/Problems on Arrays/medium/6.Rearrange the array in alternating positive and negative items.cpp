//problem :https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

/*
brute force
tc:o(2n)
sc:o(2n)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> positive;
        vector<int> negative;

        for(int i=0;i<n;i++){ //tc:o(n)
            if(nums[i]>0)positive.push_back(nums[i]);
            else negative.push_back(nums[i]);
        }

        int i=0,j=0;
        for(int k=0;k<n;){ //tc:o(n)
            if(i<n/2){
                nums[k++]=positive[i++];
            }

            if(j<n/2){
                nums[k++]=negative[j++];
            }
        }
        return nums;
    }
};

/*
better 
tc:o(n)
sc:o(n)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int pos=0,neg=1;
        for(int i=0;i<n;i++){
           if(nums[i]>0){
             ans[pos]=nums[i];
             pos+=2;
           }
           else{
            ans[neg]=nums[i];
             neg+=2;
           }
        }
         
      return ans;  
    }
};
