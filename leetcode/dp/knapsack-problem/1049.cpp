// https://leetcode-cn.com/problems/last-stone-weight-ii/submissions/
// Created by admin on 2021/6/8.
// 背包问题dp，难在问题转化

using namespace std;

#include <vector>
#include <math.h>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 转为背包问题，从 stonesstones 数组中选择，凑成总和不超过 sum/2 的最大值
        // dp[i][j] 表示从前i个里选，不超过j的最大值
        int sum = 0;
        for(int n:stones){
            sum += n;
        }
        vector<vector<int>> dp(stones.size(),vector<int>(sum,0));
        for(int j=0;j<sum;++j){
            if(j>=stones[0]){
                dp[0][j] = stones[0];
            }
        }
        for(int i=1;i<stones.size();++i){
            for(int j=0;j<sum;++j){
                dp[i][j] = dp[i-1][j];
                if(j>=stones[i]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-stones[i]]+stones[i]);
                }
            }
        }
        return dp[stones.size()-1][sum/2];
    }
};

int main(){
    vector<int> v{2,7,4,1,8,1};
    Solution s;
    s.lastStoneWeightII(v);
}