// https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/submissions/
// Created by admin on 2021/4/22.
// 原想法：四位dp超时，改进--->
// 1. 固定左右区间
// 2. 以区间内的rowSum，计算最大小于k的连续和
using namespace std;
#include <vector>

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int colNum = matrix[0].size();
        vector<int> rowSum(matrix.size());
        int res = -9999999;
        for (int i = 0; i < colNum; ++i) {
            rowSum = vector<int>(matrix.size(),0);
            for (int j = i; j < colNum; ++j) {
                for (int row = 0; row < matrix.size(); ++row) {
                    rowSum[row]+=matrix[row][j];
                }
                // subMax
                res=max(res,helper(rowSum,k));
            }
        }
        return res;
    }

    /**
     * 计算最大小于k的连续和
     * @param rowSum
     * @param k
     * @return
     */
    int helper(vector<int>& rowSum,int k){
        int res = -999999;
        int tmp = 0;
        for (int i = 0; i < rowSum.size(); ++i) {
            tmp = 0;
            for (int j = i; j < rowSum.size(); ++j) {
                tmp += rowSum[j];
                if(tmp>res&&tmp<k){
                    res = tmp;
                }
            }
        }
        return res;
    }
};