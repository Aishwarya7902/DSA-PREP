// PROBLEM :https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

/*
self
Thought process
first iterate through nums , and store in a set , this will automatically store the unique elements in sorted order
Now traverse the set and put each element at nums starting from 0th index

Time Complexity:

Inserting each of the n elements into a std::set costs O(log n) each ⇒ O(n log n).
Space Complexity:
You allocate a set of up to n elements ⇒ O(n) extra.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int k=0;
        for(auto it:s){
           nums[k++]=it;
        }
        return k;
    }
};

/*
OPTIMIZATION
USING 2 POINTER
TC:O(N)
SC:O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;

        int i=0;
        for(int j=1;j<n;j++){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                i++;
                
            }
        }
        return i+1;

    }
};
