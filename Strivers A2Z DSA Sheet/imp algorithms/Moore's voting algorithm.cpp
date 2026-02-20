/*
Majority Element-I
best
Moore's Voting Algorithm
tc:o(n)
sc:o(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      //applying the algo
        int cnt=0;
        int el;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                el=nums[i];
                cnt=1;
            }
            else if(nums[i]==el)cnt++;
            else cnt--;
        }
      // u can verify the algo too if interviewer asks
      // int cnt1=0;
      //   for(int i=0;i<nums.size();i++){
      //       if(nums[i]==el)cnt1++;
      //   }
      //   if(cnt1>nums.size()/2)return el;
        return el;
    }
};
