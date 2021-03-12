// https://leetcode-cn.com/problems/container-with-most-water/
// Created by admin on 2021/3/12.
// 双指针，两边往中间走
using namespace std;
#include <vector>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int res = 0;
        while (left<right){
            res = max((right-left)*min(height[left],height[right]),res);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
};