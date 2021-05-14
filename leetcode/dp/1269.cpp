// https://leetcode-cn.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
// Created by admin on 2021/5/14.
// 困难题，轻松拿下！

class Solution {
public:
    // dp[i][j] 走i步后在j的方案数
    // dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
    int numWays(int steps, int arrLen) {
        int mod = 1000000007;
        int sz = min(steps/2+1,arrLen);
        vector<vector<long>> dp(steps+1,vector<long>(sz));
        dp[0][0] = 1;
        for(int i=1;i<=steps;++i){
            for(int j=0;j<sz;++j){
                dp[i][j] = dp[i-1][j];
                if(j>0){
                    dp[i][j] += (dp[i-1][j-1]%mod);
                }
                if(j<sz-1){
                    dp[i][j] += (dp[i-1][j+1]%mod);
                }
            }
        }
        return dp[steps][0] % mod;
    }
};