// https://leetcode-cn.com/problems/valid-triangle-number/
// Created by admin on 2021/8/5.
// 排序+双指针，双指针部分不好理解，用了贪心的思想

using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int res = 0;
        for (int i = 0; i < nums.size()-2; ++i) {
            // i是第一个边（最小的）
            int right=i+2;
            for (int left = i+1; left < nums.size() - 1; ++left) {
                right = max(left+1,right);
                while (right<nums.size()&&nums[i]+nums[left]>nums[right]){
                    right++;
                }
                res+=(right-left-1);
            }
        }
        return res;
    }
};