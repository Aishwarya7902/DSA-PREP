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


/*
  optimization

  tc: O(m + n), where m = a.size() and n = b.size()
  sc:o(1)
  
*/

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        vector<int>result;
        
        int m=a.size();
        int n=b.size();
        
        int i=0,j=0;
        while(i<m && j<n){
            
            if(a[i]<=b[j]){
                
            if(result.size()==0 || a[i]!=result.back()){
                result.push_back(a[i]);
               
            }
             i++;
            }
            
            else{
                if(result.size()==0 || b[j]!=result.back()){
                result.push_back(b[j]);
                
            }
            j++;
            }
        }
        
        while(i<m){
           if (result.empty() || a[i] != result.back())
                result.push_back(a[i]);
            ++i;
        }
        
        while(j<n){
            if (result.empty() || b[j] != result.back())
                result.push_back(b[j]);
            ++j;
        }
        
        return result;
        
        
    }
};
