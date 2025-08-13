// problem :https://leetcode.com/problems/missing-number/description/

/*
brute force

Algorithm (step-by-step)
Let n = nums.size().

Create an empty ordered set st.

For every value v in nums, insert v into st.
(After this, st contains all numbers that appear in nums.)

For i from 0 to n (inclusive), check whether i is in st.

If i is not found (st.find(i) == st.end()), return i.

If none missing (theoretically impossible for valid input), return 0 as fallback.



tc:O(n log n)
sc:O(n)

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int>st;
        int n=nums.size();

        for(auto it:nums){ //O(n log n)
            st.insert(it);
        }

        for(int i=0;i<=n;i++){ //O(n log n)
            if(st.find(i)==st.end())return i;
        }

        return 0;
    }
};


/*

optimization

tc: 
average / expected time: Θ(n).
unordered_map provides amortized O(1) insert/find on average (hash-table).

Worst-case time: O(n²)

Space: Θ(n).

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();

        for(auto it:nums){ 
            mp[it]++;
        }

        for(int i=0;i<=n;i++){ 
            if(mp.find(i)==mp.end())return i;
        }

        return 0;
    }
};

/*
Best Aprroach
TC:O(N)
sc:O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        int sumOfNatural=n*(n+1)/2;

        int sum=0;
        for(auto it:nums){
            sum+=it;
        }

        return sumOfNatural-sum;
    }

};

/*
using xor
tc:o(n)
sc:o(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int xorr=0;

       for(int i=0;i<=nums.size();i++){
        xorr=xorr^i;
       }

       for(int i=0;i<nums.size();i++){
        xorr=xorr^nums[i];
       }
       return xorr;
    }

};
