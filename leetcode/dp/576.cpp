// https://leetcode-cn.com/problems/out-of-boundary-paths/
// Created by 陈彦泽 on 2021/8/15.
// dp[i][j][k] 表示 从坐标[i,j] 走k步【刚好】能出界的个数
// dp[i][j][k] = dp[i-1][j][k-1] + dp[i+1][j][k-1] + dp[i][j-1][k-1] + dp[i][j+1][k-1]
using namespace std;
#include <vector>

class Solution {
    int MOD = 1000000007;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove==0){
            return 0; // 特殊用例
        }
        vector<vector<int>> *dp = new vector<vector<int>>(m, vector<int>(n));
        int res = 0;
        // init
        for (int i = 0; i < m; ++i) {
            (*dp)[i][0]++;
            (*dp)[i][n-1] ++;
        }
        for (int i = 0; i < n; ++i) {
            (*dp)[0][i]++;
            (*dp)[m-1][i]++;
        }
        res += (*dp)[startRow][startColumn];
        // calculate
        for (int move = 2; move <= maxMove; ++move) {
            vector<vector<int>> *new_dp = new vector<vector<int>>(m, vector<int>(n));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if(i!=0){
                        (*new_dp)[i][j] = ((*new_dp)[i][j]+ (*dp)[i-1][j])% MOD;
                    }
                    if(i!=m-1){
                        (*new_dp)[i][j] = ((*new_dp)[i][j]+  (*dp)[i+1][j]) % MOD;
                    }
                    if(j!=0){
                        (*new_dp)[i][j] = ((*new_dp)[i][j]+  (*dp)[i][j-1]) % MOD;
                    }
                    if(j!=n-1){
                        (*new_dp)[i][j] = ((*new_dp)[i][j]+  (*dp)[i][j+1]) % MOD;
                    }
                }
            }
            res = (res + (*new_dp)[startRow][startColumn]) % MOD;
            delete dp;
            dp = new_dp;
        }
        return res;
    }
};