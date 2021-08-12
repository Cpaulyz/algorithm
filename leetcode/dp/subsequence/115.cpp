// https://leetcode-cn.com/problems/distinct-subsequences/
// Created by admin on 2021/3/17.
//

class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j]
        // 1. s[i]!=t[j]    dp[i][j] = dp[i-1][j]
        // 2. s[i]==t[j]    dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
        vector<vector<long>> dp(s.size()+1, vector<long>(t.size()+1));
        dp[0][0] = 1;
        for(long i=1;i<s.size()+1;++i){
            dp[i][0] = 1;
            for(long j=1;j<t.size()+1;++j){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};