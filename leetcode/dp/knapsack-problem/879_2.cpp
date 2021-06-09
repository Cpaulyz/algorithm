// https://leetcode-cn.com/problems/profitable-schemes/submissions/
// Created by admin on 2021/6/9.
// 三维的背包问题.. so hard


using namespace std;

#include <vector>
#include <iostream>
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // dp[i][j][k] 表示做前i种工作，参与员工=j，盈利>=k的个数
        // dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-group[i]][k-profit[i]]
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(group.size()+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,0)));
        // init
        dp[0][0][0] = 1;
        // dp
        for(int i=1;i<=group.size();++i){
            for(int j=0;j<=n;j++){
                // cout <<"<" <<i <<":" << j<<"> ";
                for(int k=0;k<=minProfit;k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    if(group[i-1]<=j){
                        int tmpk = k-profit[i-1]>=0?k-profit[i-1]:0;
                        dp[i][j][k]+=dp[i-1][j-group[i-1]][tmpk];
                    }
                    dp[i][j][k] %= mod;
                    // cout << dp[i][j][k] <<" ";
                }
                // cout << endl;
            }
        }
        int sum = 0;
        for (int j = 0; j <= n; j++) {
            sum = (sum + dp[group.size()][j][minProfit]) % mod;
        }
        return sum;
    }
};
int main() {
    Solution s;
    vector<int> g{2,2,2,2,2,2,1,2,1,1,2,1,2,2,2,1,2,1,1,2,1,2,1,2,2,2,2,1,1,2,2,2,1,1,2,1,2,2,2,1,2,2,2,2,1,2,2,1,2,2,1,1,1,1,1,1,2,2,2,2,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,2,2,1,1,2,2,2,1,1,2,2,1,1,2,2,1,2,2,1,1,2,2,2,2,2};
    vector<int> p{2,1,2,2,2,1,0,1,2,0,0,2,2,1,1,1,2,0,1,1,2,0,2,2,1,0,1,0,1,2,2,1,1,2,0,2,1,1,1,1,1,2,0,1,0,2,2,2,2,2,0,1,1,2,1,0,1,0,0,2,1,0,2,0,2,1,1,1,0,1,0,1,2,2,0,1,1,2,2,0,1,0,0,1,1,2,2,2,2,1,0,0,1,2,1,1,1,1,0,1};
    int a = s.profitableSchemes(1, 1, g, p);
}