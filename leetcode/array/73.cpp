// https://leetcode-cn.com/problems/set-matrix-zeroes/
// Created by admin on 2021/3/21.
// 复用原数组的技巧

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = 0;
        int col = 0;
        if(matrix[0][0]==0){
            row=col=1;
        }else{
            for(int i = 0;i<matrix[0].size();++i){
                if(matrix[0][i]==0){
                    row = 1;
                    break;
                }
            }
            for(int i = 0;i<matrix.size();++i){
                if(matrix[i][0]==0){
                    col = 1;
                    break;
                }
            }
        }
        // 初始化完成
        for(int i =1;i<matrix.size();++i){
            for(int j =1;j<matrix[0].size();++j){
                if(matrix[i][j]==0){
                    matrix[0][j] =matrix[i][0] = 0;
                }
            }
        }
        for(int i =1;i<matrix.size();++i){
            for(int j =1;j<matrix[0].size();++j){
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        // check first col and row
        if(row==1){
            for(int i = 0;i<matrix[0].size();++i){
                matrix[0][i]=0;
            }
        }
        if(col==1){
            for(int i = 0;i<matrix.size();++i){
                matrix[i][0]=0;
            }
        }
    }
};