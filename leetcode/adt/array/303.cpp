// https://leetcode-cn.com/problems/range-sum-query-immutable/
// Created by admin on 2021/3/1.
// 前缀和
using namespace std;
#include <vector>

class NumArray {
private:
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        preSum.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            preSum.push_back(preSum.back()+nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return preSum[j+1]-preSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */