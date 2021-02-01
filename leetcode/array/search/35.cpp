// https://leetcode-cn.com/problems/search-insert-position/
// Created by admin on 2021/2/1.
// 二分查找
// 本质上是找最小的大于等于target的元素的下标
using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 边界处理
        if(nums.size()==0){
            return 0;
        }else if(nums[nums.size()-1]<target){
            return nums.size();
        }else if(nums[0]>target) {
            return 0;
        }
        // 找最大的小于target的元素的下标
        int left = 0;
        int right = nums.size()-1;
        while (left<right){
            int mid = left+ (right-left)/2;
            if(nums[mid]<target){
                left = mid+1;
            }else{ // [mid] >= target
                right = mid;
            }
        }
        return left;
    }
};
