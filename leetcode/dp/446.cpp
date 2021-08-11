// https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/
// Created by 陈彦泽 on 2021/8/11.
// dp[i][j] 表示以第i个结尾，差为j的等差个数

using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long,int>> dp(nums.size(), unordered_map<long,int>());
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)nums[i]-nums[j];
                res += dp[j][diff];
                dp[i][diff] += (dp[j][diff]+1);
            }
        }
        return res;
    }
};