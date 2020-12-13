// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
// Created by admin on 2020/12/13.
// 最多可以完成 k 笔交易，其实k也不会太大，最多是prices.size()/2罢了
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0||k==0){
            return 0;
        }
        if(k>(prices.size()+1)/2){
            k = (prices.size()+1)/2;
        } // leetcode上是向下取整的
        int dp[prices.size()][k+1][2]; // 已经交易笔数、[持仓收益，不持仓收益];一旦购入就算+一次交易，卖出不算
        memset(dp,0,sizeof(dp));
        dp[0][1][0] = -prices[0];
        for (int i = 2; i < k + 1; ++i) {
            dp[0][i][0] = -9999999;
            dp[0][i][1] = -9999999;
        }
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j <k+1 ; ++j) {
                dp[i][j][0] = max(dp[i-1][j-1][1]-prices[i],dp[i-1][j][0]); // 马上购入，或者之前购入不卖
                dp[i][j][1] = max(dp[i-1][j][0]+prices[i],dp[i-1][j][1]); // 之前就不持仓，或者之前持仓后卖掉
            }
        }
        int profit = 0;
        for (int i = 1; i < k + 1; ++i) {
            profit = max({dp[prices.size()-1][i][0],dp[prices.size()-1][i][1],profit});
        }
        return profit;
    }
};

int main(){
    vector<int> a{1};
    Solution s;
    cout << s.maxProfit(1,a);
}