// problem :https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

/*
brute force (gives tle)
tc: o(n^2)
sc:o(1) ...we just take an array to return the ans and nothing else
*/

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int>result;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            bool strictlyGrater=true;
            
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    strictlyGrater=false;
                    break;
                }
            }
            if(strictlyGrater){
                result.push_back(arr[i]);
            }
        }
        
        return result;
    }
};

/*
better
tc:o(n)
sc:o(1)
1.Look for a way to avoid checking every element to the right of arr[i].

2.Which direction (left→right or right→left) makes it easy to know "what's the biggest thing to my right" already without another loop?

3.While scanning that direction, keep one variable maxSoFar that stores the maximum you've seen so far. Compare the current element to maxSoFar to decide if it's a leader.

4.If you scan from right→left, when arr[i] >= maxSoFar it must be a leader (update maxSoFar = arr[i]). Collect leaders as you find them.

5.Important detail: scanning right→left you'll collect leaders in reverse order (rightmost first) — either push into a deque at front, or push_back into a vector and reverse() at the end.
*/

#include <bits/stdc++.h>
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int>result;
        
        int n=arr.size();
        int maxSoFar=arr[n-1];
        for(int i=n-1;i>=0;i--){
           if(arr[i]>=maxSoFar){
               result.push_back(arr[i]);
               maxSoFar=max(maxSoFar,arr[i]);
           }
        }
        reverse(result.begin(),result.end());
        
        return result;
    }
};
