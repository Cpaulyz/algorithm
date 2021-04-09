// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Created by admin on 2021/4/9.
// 二分查找变式

class Solution {
public:
    int findMin(vector<int>& nums) {
        int tmp = 10000;
        int left =0,right =nums.size()-1;
        while(left<right){
            if(nums[left]==nums[right]){
                tmp = min(tmp,nums[left]);
                left++;
                right--;
            }else if(nums[left]<nums[right]){
                tmp = min(tmp,nums[left]);
                break;
            }else{
                int mid = left+(right-left)/2;
                if(nums[mid]>=nums[left]){
                    left =mid+1;
                }else{
                    right = mid;
                }
            }
        }
        tmp = min(tmp,nums[min(left,right)]);
        return tmp;
    }
};