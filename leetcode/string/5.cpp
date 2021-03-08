// https://leetcode-cn.com/problems/longest-palindromic-substring/
// Created by admin on 2021/3/7.
//
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        int maxLen = 1;
        int maxLeft = 0;
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
        }
        for (int i = s.size()-1; i >= 0; --i) {
            for (int j = i+1; j < s.size(); ++j) {
                if(s[i]==s[j]){
                    if(j-i==1) {
                        dp[i][j] = 1;
                    }else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    if(dp[i][j]==1&&j-i+1>maxLen){
                        maxLen = j-i+1;
                        maxLeft = i;
                    }
                }
            }
        }
        return s.substr(maxLeft,maxLen);
    }
};

int main(){
    Solution s;
    s.longestPalindrome("cbbd");
}