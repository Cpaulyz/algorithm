// https://leetcode-cn.com/problems/ones-and-zeroes/
// Created by admin on 2021/6/6.
// 三维dp。转背包问题

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j][k] 表示前i个，满足0个数<=j，1个数<=k的最大子集数
        // dp[i][j][k] =  max(dp[i-1][j][k],1+dp[i-1][j-cnt(0)][k-cnt(1)])
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,0)));
        // init
        for(int j=0;j<=m;++j){
            for(int k=0;k<=n;++k){
                int cnt0 = cnt(strs[0],'0');
                int cnt1 = cnt(strs[0],'1');
                if(cnt0<=j&&cnt1<=k){
                    dp[0][j][k] =  1;
                }
            }
        }
        // cal
        for(int i=1;i<strs.size();++i){
            int cnt0 = cnt(strs[i],'0');
            int cnt1 = cnt(strs[i],'1');
            for(int j=0;j<=m;++j){
                for(int k=0;k<=n;++k){
                    if(cnt0<=j&&cnt1<=k){
                        dp[i][j][k] =  max(dp[i-1][j][k],1+dp[i-1][j-cnt0][k-cnt1]);
                    }else{
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[strs.size()-1][m][n];
    }

    int cnt(string &str,char c){
        int res  = 0;
        for(int i=0;i<str.size();++i){
            if(str[i]==c){
                res ++ ;
            }
        }
        return res;
    }
};