// https://leetcode-cn.com/problems/knight-dialer/
// Created by 陈彦泽 on 2021/9/10.
// dp,可快速幂优化

class Solution {
    int MOD=1000000007;
public:
    int knightDialer(int n) {
        vector<vector<long>> dp(n,vector<long>(10,0));
        // init
        for(int i=0;i<10;++i){
            dp[0][i] = 1;
        }
        // dp
        for(int i=1;i<n;++i){
            dp[i][0] = (dp[i-1][4]+dp[i-1][6])%MOD;
            dp[i][1] = (dp[i-1][8]+dp[i-1][6])%MOD;
            dp[i][2] = (dp[i-1][7]+dp[i-1][9])%MOD;
            dp[i][3] = (dp[i-1][4]+dp[i-1][8])%MOD;
            dp[i][4] = (dp[i-1][3]+dp[i-1][9]+dp[i-1][0])%MOD;
            // dp[i][5] = (dp[i-1][2]+dp[i-1][4]+dp[i-1][6]+dp[i-1][8])%MOD;
            dp[i][6] = (dp[i-1][1]+dp[i-1][7]+dp[i-1][0])%MOD;
            dp[i][7] = (dp[i-1][2]+dp[i-1][6])%MOD;
            dp[i][8] = (dp[i-1][1]+dp[i-1][3])%MOD;
            dp[i][9] = (dp[i-1][2]+dp[i-1][4])%MOD;
        }
        int res = 0;
        for(int i=0;i<10;++i){
            res = (res + dp[n-1][i])%MOD;
        }
        return res;
    }
};