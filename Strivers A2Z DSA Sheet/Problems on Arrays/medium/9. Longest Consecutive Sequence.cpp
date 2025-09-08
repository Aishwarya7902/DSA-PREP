//problem :https://leetcode.com/problems/longest-consecutive-sequence/description/

/*
the most solution will be similar to better one but instead of searching a map , we will do a linear search
tc:o(n^3)
sc:o(1)

class Solution {
public:
    bool linearSearch(int target,vector<int>& arr) {
    for (int i = 0; i < (int)arr.size(); ++i)
        if (arr[i] == target) return true;
    return false;
}
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
       int result=0;
     

       //iterate in each element of the array and see how far we can go
       for(int i=0;i<n;i++){
            int elem=nums[i];
            int cnt=0;
            while(linearSearch(elem++,nums)==true){
                cnt++;
            }

            result=max(result,cnt);
       }
       return result;
    }
};


*/

/*
better  force
tc:o(n+logn)
sc:o(1)
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

       int n=nums.size();
       if(!n)return 0;
       int result=0;
       
       sort(begin(nums),end(nums));
       int  last_el=nums[0];
       int cnt=1;

       for(int i=1;i<n;i++){
           if (nums[i] == last_el) {
               // duplicate: ignore
               continue;
           }
           if(nums[i] == last_el + 1){
            cnt++;
            last_el=nums[i];
           }
           
           else{
            result=max(result,cnt);
            //make  a fresh start
            last_el=nums[i];
            cnt=1;
           }
           
       }
       result=max(result,cnt);
       return result;
    }
};

/*
best..........but but but this gives a time complexity
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
       int result=0;
       //put elements in map

       unordered_map<int,int>mp;
       for(auto it:nums){
        mp[it]++;
       }

       //iterate in each element of the array and see how far we can go
       for(int i=0;i<n;i++){
            int elem=nums[i];
            int cnt=0;
            while(mp.find(elem++)!=mp.end()){
                cnt++;
            }

            result=max(result,cnt);
       }
       return result;
    }
};

/*
most optimal
tc: In best case set will take o(1) .....if there are no  collisions ...in case of collisions , it takes o(n)
     so the time complexity will be
     o(n) -> for putting array elements in set + o(n) -> iterating in set

     
sc: o(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
       int result=0;
       //put elements in set

       unordered_set<int>st;
       for(auto it:nums){
        st.insert(it);
       }

       //iterate in each element of the set and see how far we can go..only if it's prvious does not exist
       for(auto it:st){
            int elem=it;
            if(st.find(elem-1)!=st.end())continue;
            int cnt=0;
            while(st.find(elem++)!=st.end()){
                cnt++;
            }

            result=max(result,cnt);
       }
       return result;
    }
};
