// https://leetcode-cn.com/problems/arithmetic-slices/
// Created by 陈彦泽 on 2021/8/10.
// 一次遍历dp即可

using namespace std;
#include <vector>

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int prevDiff = INT32_MAX;
        int res = 0;
        int num = 0;//  连续的个数
        for (int i = 1; i < nums.size(); ++i) {
            int tmpDiff = nums[i] - nums[i-1];
            if(prevDiff!=tmpDiff){
                prevDiff = tmpDiff;
                num = 1;
            }else{
                num++;
                res += max(num-1,0);
            }
        }
        return res;
    }
};