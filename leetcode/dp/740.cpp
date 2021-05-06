// https://leetcode-cn.com/problems/delete-and-earn/
// Created by admin on 2021/5/6.
// 动态规划 dp[i][j] 表示选择0..i里面,j=1代表选i,j=0代表不选j
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> sort_record;
        for(int n:nums){
            if(map[n]==0){
                sort_record.push_back(n);
            }
            map[n]++;
        }
        sort(sort_record.begin(),sort_record.end());
        // dp[i][j] 表示选择0..i里面,j=1代表选i,j=0代表不选j
        vector<vector<int>> dp(sort_record.size(),vector<int>(2,0));
        dp[0][1] = sort_record[0]*map[sort_record[0]];
        for (int i = 1; i < dp.size(); ++i) {
            // calculate dp[i][0]
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            // calculate dp[i][1]
            if(sort_record[i]-sort_record[i-1]==1){
                dp[i][1] = dp[i-1][0] + sort_record[i]*map[sort_record[i]];
            }else{
                dp[i][1] = max(dp[i-1][0],dp[i-1][1]) + sort_record[i]*map[sort_record[i]];
            }
        }
        return max(dp[dp.size()-1][0],dp[dp.size()-1][1]);
    }
};