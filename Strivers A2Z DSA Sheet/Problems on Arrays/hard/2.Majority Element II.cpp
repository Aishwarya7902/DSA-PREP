// problem : https://leetcode.com/problems/majority-element-ii/description/

/*
brute 
for every element ...loop and find how many times it occurs in the whole array
tc:o(n^2)
sc:o(1)
*/

/*
better
->find out freq of each element
->if freq of any element is > [n/3] put in result
->return result

TC:O(N)
SC:O(N)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();

        unordered_map<int,int>mp;

        for(auto it:nums){
            mp[it]++;
        }

        for(auto it:mp){
            if(it.second>floor(n/3))result.push_back(it.first);
        }

        return result;
    }
};

/*
best
tc:o(n)
sc:o(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();
         
        int count1=0,elem1;
        int count2=0,elem2;

        for(int i=0;i<n;i++){
            if(count1==0 && nums[i]!=elem2){
                count1=1;
                elem1=nums[i];
            }
            else if(count2==0 && nums[i]!=elem1){
                count2=1;
                elem2=nums[i];
            }
            else if(nums[i]==elem1)count1++;
            else if(nums[i]==elem2)count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1=0,count2=0;
        for(int i=0;i<n;i++){
             if(nums[i]==elem1)count1++;
        }
        for(int i=0;i<n;i++){
             if(nums[i]==elem2)count2++;
        }
        if(count1>floor(n/3))result.push_back(elem1);
        if(count2>floor(n/3))result.push_back(elem2);
        

       return result;   
         
    }
};
