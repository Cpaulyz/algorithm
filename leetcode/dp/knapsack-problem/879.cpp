// https://leetcode-cn.com/problems/profitable-schemes/
// Created by admin on 2021/3/11.
// 0-1背包问题，阿里笔试题
// dp[i][j][k] 表示对于前i个项目，出j个人可以获得profit>=k的选择个数
// dp[i][j][k] = dp[i-1][j][k]+dp[i-1][j-group[i-1]][k-group[i-1]]
using namespace std;

#include <vector>

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
        int mod = 10^9 + 7;
//        vector<vector<vector<int>>> dp(group.size()+1,vector<vector<int>>(n+1,vector<int>(minProfit+1)));
        // init
//        for (int i = 0; i < group.size()+1; ++i) {
//            for (int j = 0; j < n+1; ++j) {
//                dp[i][j][0] = 1;
//            }
//        }
        vector<vector<int>> dp(n+1,vector<int>(minProfit+1));
        for (int i = 0; i < n + 1; ++i) {
            dp[i][0] = 1;
        }
//        for (int i = 1; i <group.size()+1; ++i) {
//            for (int j = 1; j <n+1; ++j) {
//                for (int k = 0; k < minProfit+1; ++k) {
//                    dp[i][j][k]=dp[i-1][j][k];
//                    if(j>=group[i-1]){
//                        dp[i][j][k] += dp[i-1][j-group[i-1]][max(k-profit[i-1],0)];
//                    }
//                }
//            }
//        }
        for (int i = 1; i <group.size()+1; ++i) {
            vector <vector<int>> dp1 = dp;
            for (int j = 1; j < n + 1; ++j) {
                for (int k = 0; k < minProfit + 1; ++k) {
                    dp[j][k] = dp1[j][k];
                    if (j >= group[i - 1]) {
                        dp[j][k] += dp1[j - group[i - 1]][max(k - profit[i - 1], 0)];
                        dp[j][k] %= mod;
                    }
                }
            }
        }
//        return dp[group.size()][n][minProfit];
        return dp[n][minProfit];
    }
};

int main() {
    Solution s;
    vector<int> g{2, 2};
    vector<int> p{2, 3};
    int a = s.profitableSchemes(5, 3, g, p);
}