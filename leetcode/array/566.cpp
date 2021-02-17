// https://leetcode-cn.com/problems/reshape-the-matrix/
// Created by admin on 2021/2/17.
// 一维数组的二维表示法
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(r*c!=nums.size()*nums[0].size()){
            return nums;
        }else{
            vector<vector<int>> res(r,vector<int>(c));
            int nc = nums[0].size();
            for (int i = 0; i < r * c; ++i) {
                res[i/c][i%c] = nums[i/nc][i%nc];
            }
            return res;
        }
    }
};