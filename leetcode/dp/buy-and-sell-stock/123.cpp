// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
// Created by admin on 2020/12/13.
// 只能进行两笔交易
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int dp[prices.size()][3][2]; // 已经交易笔数、[持仓收益，不持仓收益];一旦购入就算+一次交易，卖出不算
        memset(dp,0,sizeof(dp));
        dp[0][1][0] = -prices[0];
        dp[0][2][0] = -9999999;
        dp[0][2][1] = -9999999;
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j <3 ; ++j) {
                dp[i][j][0] = max(dp[i-1][j-1][1]-prices[i],dp[i-1][j][0]); // 马上购入，或者之前购入不卖
                dp[i][j][1] = max(dp[i-1][j][0]+prices[i],dp[i-1][j][1]); // 之前就不持仓，或者之前持仓后卖掉
            }
        }
        return max({dp[prices.size()-1][1][0],dp[prices.size()-1][1][1],dp[prices.size()-1][2][0],dp[prices.size()-1][2][1],0});
    }
};

int main(){
    vector<int> a{3,3,5,0,0,3,1,4};
    Solution s;
    s.maxProfit(a);
}
