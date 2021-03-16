// https://leetcode-cn.com/problems/trapping-rain-water/
// Created by admin on 2021/3/16.
// 双指针解法，左右往中间缩，总是移动较矮的指针
using namespace std;
#include <vector>
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2){
            return 0;
        }
        int left = 0,right = height.size()-1;
        int leftBound = height[left],rightBound = height[right];
        int res=0;
        while (left<right){
            if(height[left]<height[right]){
                left++;
                leftBound = max(height[left],leftBound);
                res += leftBound-height[left];
                // cout<<"left"<<left <<" "<<res<<endl;
            }else{
                right--;
                rightBound = max(height[right],rightBound);
                res += rightBound-height[right];
                // cout<<"right"<<right <<" "<<res<<endl;
            }
        }
        return res;
    }
};