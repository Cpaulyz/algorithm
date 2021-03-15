//https://leetcode-cn.com/problems/regular-expression-matching/
// Created by admin on 2021/3/15.
// dp[i][j] 表示s[0..i] p[0..j]能否匹配
// 难点在于状态转移
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1));
        dp[0][0] = true;
        // init i=0
        for (int j = 1; j < p.size() + 1; ++j) {
            if(p[j-1]=='*') dp[0][j] = dp[0][j-2];
        }
        for (int i = 1; i < s.size()+1; ++i) {
            for (int j = 1; j <p.size()+1; ++j) {
                if(s[i-1]==p[j-1]||p[j-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                    if(p[j-2]=='.'){ // xxxa .*
                        // 选择 要 || 第一次要 || 不要
                        dp[i][j] = dp[i-1][j]||dp[i][j-1]||dp[i][j-2];
                    }else if(s[i-1]==p[j-2]){ // xxxa xxxa*
                        // 选择 要 || 第一次要 || 不要
                        dp[i][j] = dp[i-1][j]||dp[i][j-1]||dp[i][j-2];
                    }else{ //  xxxb  xxxa* 舍弃
                            dp[i][j] = dp[i][j-2];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main(){

    Solution s;
    bool  res = s.isMatch("aab","c*a*b");
}