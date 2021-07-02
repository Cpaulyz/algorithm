// https://leetcode-cn.com/problems/array-partition-i/
// Created by admin on 2021/2/16.
//
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i+=2) {
            res+=nums[i];
        }
        return res;
    }
};