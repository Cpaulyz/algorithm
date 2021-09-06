// https://leetcode-cn.com/problems/binary-search/
// Created by 陈彦泽 on 2021/9/6.
// 二分模板题
using namespace std;

#include <vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size();
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return -1;
    }
};