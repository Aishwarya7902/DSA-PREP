//problem : https://leetcode.com/problems/single-number/

/*
 brute force 
 tc: o(n) + o(n)
 sc:o(n)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }

        for(auto it:nums){
            if(mp[it]==1)return it;
        }

        return 1;
    }
};


/*
optimisation
tc:o(n)
sc:o(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr=0;
        for(auto it:nums){
            xorr= xorr^it;
        }

       
        return xorr;
    }
};
