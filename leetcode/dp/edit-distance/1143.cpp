// https://leetcode-cn.com/problems/longest-common-subsequence/
// Created by admin on 2021/3/6.
// DP,dp[i][j]表示text1[0:i]，text2[0:j]的最长公共子串
// 实现时为了方便，把i,j=0的时候置为0
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1));
        for (int i = 1; i < text1.size()+1; ++i) {
            for (int j = 1; j < text2.size()+1; ++j) {
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};