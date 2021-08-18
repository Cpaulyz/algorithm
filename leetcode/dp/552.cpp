// https://leetcode-cn.com/problems/student-attendance-record-ii/
// Created by 陈彦泽 on 2021/8/18.
// dp[i][j][k] 表示 i个人，最后连续迟到了j天，一共缺勤k天的可能数
// 1. i是P的情况: dp[i][0][k] += dp[i-1][all][k]
// 2. i是A的情况: dp[i][0][k] += dp[i-1][all][k-1]
// 3. i是L的情况: dp[i][j][k] += dp[i-1][j-1][k]
// i的状态只依靠i-1，做一个空间优化

using namespace std;

#include <vector>

class Solution {
    int MOD = 1000000007;
public:
    int checkRecord(int n) {
        int dp[3][2];
        memset(dp,0,sizeof(dp));
        // init
        // P
        dp[0][0]++;
        // A
        dp[0][1]++;
        // L
        dp[1][0]++;
        // calculate
        for (int i = 2; i <= n; ++i) {
            int newDp[3][2];
            memset(newDp,0,sizeof(dp));
            // P
            for (int k = 0; k < 2; ++k) {
                for (int j = 0; j < 3; ++j) {
                    newDp[0][k] = (newDp[0][k] + dp[j][k])%MOD;
                }
            }
            // A
            for (int j = 0; j < 3; ++j) {
                newDp[0][1] =(newDp[0][1] + dp[j][0])%MOD;
            }
            // L
            for (int j = 1; j < 3; ++j) {
                for (int k = 0; k < 2; ++k) {
                    newDp[j][k] =(newDp[j][k] + dp[j-1][k])%MOD;
                }
            }
            memcpy(dp,newDp, sizeof(dp));
        }
        // get res
        int res = 0;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                res =(res + dp[j][k])%MOD;
            }
        }
        return res;
    }
};