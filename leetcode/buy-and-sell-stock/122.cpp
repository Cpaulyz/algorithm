// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
// Created by admin on 2020/12/13.
// 和121的差别在于可以无限次进行买卖
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int dp[prices.size()][2]; // 每位表示[持仓收益，不持仓收益]
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i-1][1]-prices[i],dp[i-1][0]); // 马上购入，或者之前购入不卖
            dp[i][1] = max(dp[i-1][0]+prices[i],dp[i-1][1]); // 之前就不持仓，或者之前持仓后卖掉
        }
        return max(dp[prices.size()-1][0],dp[prices.size()-1][1]);
    }
};
