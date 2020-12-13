// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
// Created by admin on 2020/12/13.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        vector<vector<int>> dp; // 每位表示[持仓收益，不持仓收益]
        dp.push_back({-prices[0],0});
        for (int i = 1; i < prices.size(); ++i) {
            int a = max(-prices[i],dp[i-1][0]); // 马上购入，或者之前购入不卖
            int b = max(dp[i-1][0]+prices[i],dp[i-1][1]); // 之前就不持仓，或者之前持仓后卖掉
            dp.push_back({a,b});
        }
        return max(dp[prices.size()-1][0],dp[prices.size()-1][1]);
    }
};