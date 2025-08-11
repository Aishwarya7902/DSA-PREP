//PROBLEM : https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

/*
brute force
first take a set
traverse in a and put distinct elements in set

traverse in b and put distinct elements in set

now put all the elements in result vector

tc: mlogm + nlogn + (m+n)
sc: o(m+n)
*/


class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        
        set<int>st;
        for(auto it:a){ // tc:o(mlogm)
            st.insert(it);
        }
        
        for(auto it:b){// tc:o(nlogn)
            st.insert(it);
        }
        
        vector<int> result;
        for(auto it:st){  // tc:o(m+n)
            result.push_back(it);
        }
        
        return result;
    }
};
