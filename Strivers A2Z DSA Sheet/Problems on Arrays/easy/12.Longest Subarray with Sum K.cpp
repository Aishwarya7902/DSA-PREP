//https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1


/*
brute force
tc:o(n^2)
sc:o(1)
*/

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int result=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==k){
                    result=max(result,j-i+1);
                }
            }
        }
        
        return result;
    }
};

/*
better 

tc:o(n^logn)
sc:o(n)
NOTE :BETTER SOLUTION WORKS FOR BOTH +VE AND -VE Numbers
*/

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<long long,int>mp;
        long long sum=0;
        int maxLen=0;

    for(int i=0;i<arr.size();i++){
         sum+=arr[i];

         if(sum==k){
             maxLen=max(maxLen,i+1);
         }

         long long rem=sum-k;
         if(mp.find(rem)!=mp.end()){
             int len= i-mp[rem];

             maxLen=max(maxLen,len);
         }

         if(mp.find(sum)==mp.end()){
             mp[sum]=i;

         }
        
    }
    return maxLen;
    }
};


/*
best
TC:O(2n)
SC:O(1)

NOTE :BEST SOLUTION WORKS FOR BOTH +VE Numbers
*/
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        long long sum=0;
        int maxLen=0;
        
        int left=0,right=0;
        while(right<n)
        {
            sum+=arr[right];
            while(left <= right && sum>k){
                sum-=arr[left];
                left++;
            }
            
            if(sum==k){
                maxLen=max(maxLen,right-left+1);
            }
            
            right++;
        }
        return maxLen;
    }
};
