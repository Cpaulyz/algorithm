// https://leetcode-cn.com/problems/target-sum/
// Created by admin on 2021/6/7.
// dp 类似背包问题

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n:nums){
            sum += n;
        }
        if(target>sum || target<(-sum)){ // 防溢出
            return 0;
        }
        // dp[i][j] 表示前i项，合为(j-sum)的情况个数
        vector<vector<int>> dp(nums.size(),vector<int>(sum*2+1,0));
        dp[0][sum+nums[0]]++;
        dp[0][sum-nums[0]]++;
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<sum*2+1;++j){
                if(dp[i-1][j]!=0){
                    dp[i][j+nums[i]] += (dp[i-1][j]);
                    dp[i][j-nums[i]] += (dp[i-1][j]);
                }
            }
        }
        return dp[nums.size()-1][target+sum];
    }
};