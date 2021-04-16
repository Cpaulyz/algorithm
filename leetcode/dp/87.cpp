//https://leetcode-cn.com/problems/scramble-string/
// Created by admin on 2021/4/16.
// 三维dp
// dp[i][j][k] s1[i:i+k] s2[j:j+k]
// dp[i][j][k] = dp[i][j][k']&&dp[i+k'][j+k'][k-k'] ||  dp[i][j+k-k'][k']&& dp[i+k'][j][k-k']
using namespace std;
#include <string>
#include <vector>
class Solution {
    vector<vector<vector<bool>>> dp;
public:
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()){
            return false;
        }
        dp = vector<vector<vector<bool>>>(s1.length(),vector<vector<bool>>(s1.length(),vector<bool>(s1.length()+1, false)));
        // init
        for (int i = 0; i < s1.length(); ++i) {
            for (int j = 0; j < s1.length(); ++j) {
                if(s1[i]==s2[j]){
                    dp[i][j][1]=true;
                }
            }
        }
        for (int len = 2; len <= s1.length(); ++len) {
            for (int i = 0; i < s1.length()-len+1; ++i) {
                for (int j = 0; j < s1.length()-len+1; ++j) {
                    for (int k = 1; k < len; ++k) {
                        bool tmp = (dp[i][j][k]&&dp[i+k][j+k][len-k])||(dp[i][j+len-k][k]&& dp[i+k][j][len-k]);
                        if(tmp){
                            dp[i][j][len] = tmp;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][s1.length()];
    }
};