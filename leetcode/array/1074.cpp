// https://leetcode-cn.com/problems/number-of-submatrices-that-sum-to-target/submissions/
// Created by admin on 2021/5/29.
// 非常非常的好题，基本上是二维前缀的大汇总
// 可以参考363
// 1. dp算前缀和
// 2. 用四条边来限制矩阵，并用用哈希表来记录，从而把复杂度从O(n4)将为O(n3)

using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        // dp构造前缀数组
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        for (int i = 1; i < row + 1; ++i) {
            for (int j = 1; j < col + 1; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        // 记录 合:个数，降低复杂度
        unordered_map<int,int> record;
        // 固定左右边界
        for (int l = 1; l <=col; ++l) {
            for (int r = l; r <=col ; ++r) {
                record = unordered_map<int,int>();
                for (int line = 1; line <=row; ++line) {
                    int tmp = dp[line][r] - dp[line][l-1];
                    if(tmp==target){
                        res ++;
                    }
                    res += record[tmp-target];
                    record[tmp]++;
                }
            }
        }
        return res;
    }
};