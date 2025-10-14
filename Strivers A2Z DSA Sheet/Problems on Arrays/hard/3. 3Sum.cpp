//problem :https://leetcode.com/problems/3sum/submissions/1801604249/

/*
brute force 
tc:o(n^3)
sc:o(1)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> result;
         
         vector<int>curr;
         set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        curr.clear();
                        curr.push_back(nums[i]);
                        curr.push_back(nums[j]);
                        curr.push_back(nums[k]);
                        sort(begin(curr),end(curr));
                        st.insert(curr);
                    }
                }
            }
        }

        for(auto it:st){
            result.push_back(it);
        }

        return result;
    }
};

/*
optimisation
tc:o(nlogn +n^2)
sc:o(1)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
         vector<vector<int>> result;
         sort(begin(nums),end(nums));
         
         for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                        result.push_back({nums[i], nums[j], nums[k]});
                        while (j < k && nums[j] == nums[j + 1]) ++j;
                        while (j < k && nums[k] == nums[k - 1]) --k;
                        ++j;
                        --k;
                    }
                else if(sum>0){
                    k--;
                }
                else {
                     
                     j++;
                }
            }
         }

       

        return result;
    }
};
