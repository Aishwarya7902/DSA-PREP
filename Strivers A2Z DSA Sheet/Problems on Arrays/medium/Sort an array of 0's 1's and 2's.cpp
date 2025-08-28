//PROBLEM :https://leetcode.com/problems/sort-colors/

/*
tc: o(2n)
sc:o(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        int n=nums.size();
        vector<int> result(n,0);
        for(auto it:nums){
            if(it==0)zero++;
            else if(it==1)one++;
            else two++;

        }

        for(int i=0;i<n;){
            while(zero--){
                result[i++]=0;
                
            }
            while(one--){
                result[i++]=1;
                
            }
            while(two--){
                result[i++]=2;
                
            }
        }
        nums=result;

    }
};

/*
better (using sorting......but this ques restricts it)
tc:O(nlogn)
sc:o(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(begin(nums),end(nums));
    }
};

/*
best (using dutch national flag algorithm)
tc:o(n)
sc:o(1)

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n=nums.size();
        int low=0,mid=0,high=n-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
