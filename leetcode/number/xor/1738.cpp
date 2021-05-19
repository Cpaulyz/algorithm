// https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value/
// Created by admin on 2021/5/19.
// 前缀异或+优先队列

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m,n;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // 小顶堆，存大一半的
        priority_queue<int, vector<int>, greater<int>> small_heap;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                dp[i][j]=dp[i][j-1]^dp[i-1][j]^dp[i-1][j-1]^matrix[i-1][j-1];
                if(small_heap.size()<k){
                    small_heap.push(dp[i][j]);
                }else if(small_heap.top()<dp[i][j]){
                    small_heap.push(dp[i][j]);
                    small_heap.pop();
                }
            }
        }
        return small_heap.top();
    }
};