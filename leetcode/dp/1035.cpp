// https://leetcode-cn.com/problems/uncrossed-lines/submissions/
// Created by admin on 2021/5/21.
// dp[i][j] 表示 num1[0:i],num2[0:j]中的最大连线数。迁移函数需要画图理解，算是好题！

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        // dp[i][j] 表示 num1[0:i],num2[0:j]中的最大连线数
        // 移动情况，需要画图理解，算是好题！
        int res = 0;
        for(int i=1;i<=nums1.size();++i){
            for(int j=1;j<=nums2.size();++j){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    dp[i][j] = max(dp[i][j],1+dp[i-1][j-1]);
                    res = max(res,dp[i][j]);
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return res;
    }
};