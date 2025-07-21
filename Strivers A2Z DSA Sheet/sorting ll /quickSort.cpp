//problem :https://leetcode.com/problems/sort-an-array/submissions/1706305497/

//TC: O(nlogn)
//SC :O(1)

class Solution {
public:
    int partition(vector<int>& nums,int low ,int high){
        int pivot=nums[low], i=low,j=high;
        while(i<j){
            while(nums[i]<=pivot && i<high){
                i++;
            }
            while(nums[j]>pivot && j>low){
             j--;
            }
           if(i<j) swap(nums[i],nums[j]);


        }

        swap(nums[j],nums[low]);
        return j;
    }
    void quickSort(vector<int>& nums,int low ,int high){
        if(low<high){
            int pIndex=partition(nums,low,high);
            quickSort(nums,low,pIndex-1);
            quickSort(nums,pIndex+1,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        quickSort(nums,low,high);
        return nums;
    }
};
