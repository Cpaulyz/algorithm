// https://leetcode-cn.com/problems/coin-change-2/
// Created by admin on 2020/12/13.
// 完全背包问题
// dp[i][j] 的定义如下：
// 若只使用 coins 中的前 i 个硬币的面值，若想凑出金额 j，有 dp[i][j] 种凑法。
#include <vector>
#include "memory.h"

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int dp[coins.size() + 1][amount + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < coins.size() + 1; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < coins.size() + 1; ++i) {
            for (int j = 1; j < amount + 1; ++j) {
//                dp[i][j] = dp[i - 1][j];
//                int temp = j;
//                while (temp - coins[i - 1] >= 0) {
//                    dp[i][j] += dp[i - 1][temp - coins[i - 1]];
//                    temp -= coins[i - 1];
//                }
                if (j - coins[i - 1] >= 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};
