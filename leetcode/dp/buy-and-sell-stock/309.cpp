// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Created by admin on 2020/12/13.
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)；交易次数无限 122拓展题
// 与122的差别仅在于：dp[i][0] = max(dp[i-2][1]-prices[i],dp[i-1][0]);，这里用了i-2罢了
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
            if(i==1){
                dp[i][0] = max(-prices[i],dp[i-1][0]);
            } else{
                dp[i][0] = max(dp[i-2][1]-prices[i],dp[i-1][0]); // 马上购入，或者之前购入不卖
            }
            dp[i][1] = max(dp[i-1][0]+prices[i],dp[i-1][1]); // 之前就不持仓，或者之前持仓后卖掉
        }
        return max(dp[prices.size()-1][0],dp[prices.size()-1][1]);
    }
};

