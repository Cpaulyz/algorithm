// https://leetcode-cn.com/problems/toeplitz-matrix/submissions/
// Created by admin on 2021/2/22.
// 遍历，大水
using namespace std;
#include <vector>

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 1;i<matrix.size();++i){
            for(int j =1;j<matrix[0].size();++j){
                if(matrix[i][j]!=matrix[i-1][j-1]){
                    return false;
                }
            }
        }
        return true;
    }
};