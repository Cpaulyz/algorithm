// https://leetcode-cn.com/problems/partition-equal-subset-sum/
// Created by admin on 2020/12/13.
// 子集背包问题
// dp[i][j]表示对于前i个数字，能否凑到刚好和为j，可以的话为true，否则为false
#include <vector>
#include "memory.h"
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n:nums){
            sum+=n;
        }
        if(sum%2==1){
            return false; // 和为奇数，显然不行
        }
        bool dp[nums.size()+1][sum/2+1];
        memset(dp, false,sizeof(dp));
        for (int i = 0; i < nums.size() + 1; ++i) {
            dp[i][0] = true;
        } // 初始化 basic mode
        for (int i = 1; i < nums.size()+1; ++i) {
            for (int j = 1; j < sum / 2 + 1; ++j) {
                if(j-nums[i-1]<0){
                    dp[i][j] = false; // 如果第i个数太大了，显然不行
                }else{
                    dp[i][j] = dp[i-1][j]||dp[i-1][j-nums[i-1]]; // 选择，或者不选
                }
                if(j==sum / 2&&dp[i][j]){ // 找到一个符合的就可以返回，节省时间
                    return true;
                }
            }
        }
        return dp[nums.size()][sum/2];
    }
};