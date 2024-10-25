PROBLEM :https://leetcode.com/problems/insert-delete-getrandom-o1/

#include<bits/stdc++.h>
class RandomizedSet {
public:
    unordered_set<int>st;
    RandomizedSet() {
        st.clear();
    }
    
    bool insert(int val) {
        //if not present
        if(st.find(val)==st.end()){
            st.insert(val);
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        //if present ,remove it
        if(st.find(val)!=st.end()){
            st.erase(val);
            return true;
        }

        return false;
    }
    
    int getRandom() {
        vector<int>curr(st.begin(),st.end());
        int random=rand()%curr.size();
        return curr[random];
    }
};
