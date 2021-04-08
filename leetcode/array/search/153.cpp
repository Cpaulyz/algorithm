// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
// Created by admin on 2021/4/8.
// 二分查找变种

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right-1){
            if(nums[left]<nums[right]){
                return nums[left];
            }else{ // nums[left] > nums[right]
                int mid = left + (right-left+1)/2;
                if(nums[mid]>nums[left]){
                    left = mid+1;
                }else{
                    right = mid;
                }
            }
        }
        return min(nums[left],nums[right]);
    }
};