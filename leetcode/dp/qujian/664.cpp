// https://leetcode-cn.com/problems/strange-printer/submissions/
// Created by admin on 2021/5/24.
// 区间dp，转移函数不好想

class Solution {
public:
    int strangePrinter(string s) {
        // 区间dp, dp[i][j]表示打印s[i:j]所需要的最少次数
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),999));
        // init
        for(int i=0;i<s.size();++i){
            dp[i][i] = 1;
        }
        for(int gap=1;gap<s.size();++gap){
            for(int i=0;i<s.size()-gap;++i){
                // dp[i][i+gap]
                if(s[i]==s[i+gap]){
                    dp[i][i+gap] = dp[i][i+gap-1];
                }else{
                    for(int k=i;k<i+gap;++k){
                        dp[i][i+gap] = min(dp[i][i+gap],dp[i][k]+dp[k+1][i+gap]);
                    }
                }
                // cout << "<" << i <<"," << i+gap <<":"<< dp[i][i+gap]<<">  ";
            }
            // cout << endl;
        }
        return dp[0][s.size()-1];
    }
};