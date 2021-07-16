// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
// Created by admin on 2021/7/16.
// 二分

using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while (left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target){
                return count(nums,target,mid); // cnt
            } else if(nums[mid]<target){
                left++;
            }else if (nums[mid]>target){
                right--;
            }
        }
        return 0;
    }

    int count(vector<int>& nums, int target,int pos){
        int res = -1;
        for (int i = pos; i < nums.size(); ++i) {
            if(nums[i]==target){
                res++;
            }
        }
        for (int i = pos; i >=0; --i) {
            if(nums[i]==target){
                res++;
            }
        }
        return res;
    }
};