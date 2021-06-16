// https://leetcode-cn.com/problems/stone-game/
// Created by admin on 2021/6/16.
// 区间dp.. 没想到答案直接return true就完事了

using namespace std;
#include <vector>
#include <iostream>

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int sum = 0;
        for(int p:piles){
            sum += p;
        }
        // 区间dp
        // dp[i][j] 表示从[i,..,j]取，能取到的最多个数，j-i为奇数，也就是说[i,..,j]有偶数个石子
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),0));
        for (int j = 0; j <= piles.size() - 2; ++j) {
            dp[j][j+1] = max(piles[j],piles[j+1]);
        }
        cout <<  piles.size()/2;
        for (int i = 4; i <= piles.size(); i+=2) { // 间距
            for (int j = 0; j <= piles.size() - i; ++j) {
                // calculate dp[j][j+i-1]
                dp[j][j+i-1] = max(piles[j]+min(dp[j+1][j+i-2],dp[j+2][j+i-1]),
                                   piles[j+i-1]+min(dp[j+1][j+i-2],dp[j][j+i-3]));
            }
        }
        return dp[0][piles.size()-1]*2>sum;
    }
};

int main(){
    Solution s;
    vector<int> v{5,3,4,5};
    s.stoneGame(v);
}