// https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
// Created by 陈彦泽 on 2021/9/13.
// 类似576，记忆化搜索dp

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),1));
        bool end = false;
        while(!end){
            end = true;
            vector<vector<int>> new_dp(matrix.size(),vector<int>(matrix[0].size(),1));
            for(int i=0;i<matrix.size();++i){
                for(int j=0;j<matrix[0].size();++j){
                    int tmp = dp[i][j];
                    if(i!=0&&matrix[i][j]<matrix[i-1][j]){
                        tmp = max(tmp,dp[i-1][j]+1);
                    }
                    if(i!=matrix.size()-1&&matrix[i][j]<matrix[i+1][j]){
                        tmp = max(tmp,dp[i+1][j]+1);
                    }
                    if(j!=0&&matrix[i][j]<matrix[i][j-1]){
                        tmp = max(tmp,dp[i][j-1]+1);
                    }
                    if(j!=matrix[0].size()-1&&matrix[i][j]<matrix[i][j+1]){
                        tmp = max(tmp,dp[i][j+1]+1);
                    }
                    new_dp[i][j] = tmp;
                    if(tmp!=dp[i][j]){
                        end = false;
                    }
                    // cout << tmp << " ";
                }
                // cout <<endl ;
            }
            // cout << "======"<<endl;
            dp = new_dp;
        }
        int res = 0;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                res = max(res,dp[i][j]);
            }
        }
        return res;
    }
};