// https://leetcode-cn.com/problems/longest-palindromic-subsequence/
// Created by 陈彦泽 on 2021/8/12.
// dp[i][j] 表示 s[i..j] 包含的最长子串
// dp[i][j] = s[i]==s[j]? dp[i+1][j-1]+2 : max(dp[i+1][j],dp[i][j-1])

using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),1));
        // init
        for (int i = 0; i < s.size() - 1; ++i) {
            if(s[i]==s[i+1]){
                dp[i][i+1] = 2;
            }
        }
        // calculate
        for (int diff = 2; diff < s.size(); ++diff) {
            for (int i = 0; i < s.size() - diff; ++i) {
                if(s[i]==s[i+diff]){
                    dp[i][i+diff] = dp[i+1][i+diff-1]+2;
                }else{
                    dp[i][i+diff] =  max(dp[i+1][i+diff],dp[i][i+diff-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};