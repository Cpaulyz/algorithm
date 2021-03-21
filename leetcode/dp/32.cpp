// https://leetcode-cn.com/problems/longest-valid-parentheses/
// Created by admin on 2021/3/21.
// dp
using namespace std;

#include <vector>
#include <string>

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size());
        if(s.size()<2){
            return 0;
        }
        int res = 0;
        if(s[0]=='('&&s[1]==')'){
            dp[1] = 1;
            res = max(dp[1],res);
        }
        for (int i = 2; i < s.size(); ++i) {
            if(s[i]=='('){
                dp[i] = 0;
            }else if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i] = 1+dp[i-2];
                }else{ // s[i-1] = ')'
                    if(s[i-1-dp[i-1]]=='('){
                        dp[i] = 1+dp[i-1]+dp[i-2-dp[i-1]];
                    }
                }
            }
            res = max(dp[i],res);
        }
        return res;
    }
};

int main(){
    Solution s;
    s.longestValidParentheses("())");
}