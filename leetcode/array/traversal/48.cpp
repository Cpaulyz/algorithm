// https://leetcode-cn.com/problems/rotate-image/
// Created by admin on 2021/3/22.
// 变着花样遍历罢了

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int offset = 0;
        for(;offset<=size/2;++offset){
            for(int i=offset;i<size-1-offset;++i){
                int tmp = matrix[offset][i];
                matrix[offset][i] = matrix[size-1-i][offset];
                // cout << matrix[offset][i] << " ";
                matrix[size-1-i][offset] = matrix[size-1-offset][size-1-i];
                // cout << matrix[size-1-i][offset] << " ";
                matrix[size-1-offset][size-1-i] = matrix[i][size-1-offset];
                // cout << matrix[size-1-offset][size-1-i] << " ";
                matrix[i][size-1-offset] = tmp;
                // cout << matrix[i][size-1-offset] << endl;
            }
        }
    }
};