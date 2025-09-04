// problem :https://leetcode.com/problems/next-permutation/description/

/*
brute force
step1 ->generate all the permutations and in sorted form
step2 ->find the index of given array in the above list
step3-> return (i+1)th index  
edge case -> if index==n-1 ...then return 0th array obtained from list in step2

tc: o(n!*n)


*/

/*
better using stl

*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      next_permutation(nums.begin(),nums.end());
       
    }
}; 


/*
best
tc : o(n) + o(n) + o(n) =o(3n) in worst case
sc:o(1)

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int indx=-1,n=nums.size();
      //finding the dip point
      for(int i=n-2;i>=0;i--){ //tc:o(n)
        if(nums[i]<nums[i+1]){
            indx=i;
            break;
        }
      }

    //edge case ...we did not find any dip , it means it is the largest permutation
    if(indx==-1){
        reverse(nums.begin(),nums.end()); //tc:o(n)
    }

    else{
        
        //find someone greater than a[indx] which is smallest in the range indx+1 to n-1
        for(int i=n-1;i>indx;i--){//tc:o(n)
        if(nums[i]>nums[indx]){
            swap(nums[i],nums[indx]);
            break;   
          }   
        }
        //from indx+1 make all in sorted order
        reverse(nums.begin()+indx+1,nums.end());//tc:o(n)
    }
      
    

       
    }
};
