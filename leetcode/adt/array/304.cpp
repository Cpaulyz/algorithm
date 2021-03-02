// https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
// Created by admin on 2021/3/2.
// 二维前缀和
using namespace std;
#include <vector>
class NumMatrix {
    vector<vector<int>> pre;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0){ // 边界处理
            pre =  vector<vector<int>>(1,vector<int>(1,0));
            return;
        }
        pre = vector<vector<int>>(matrix.size()+1,vector<int>(matrix[0].size()+1));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                pre[i+1][j+1] = pre[i][j+1] + pre[i+1][j] - pre[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2+1][col2+1] - pre[row2+1][col1] - pre[row1][col2+1] + pre[row1][col1];
    }
};

int main(){
    vector<vector<int>> v;
    v.push_back({3, 0, 1, 4, 2});
    v.push_back({5, 6, 3, 2, 1});
    v.push_back({1, 2, 0, 1, 5});
    v.push_back({4, 1, 0, 1, 7});
    v.push_back({1, 0, 3, 0, 5});
    NumMatrix numMatrix(v);
    numMatrix.sumRegion(2,1,4,3);
    numMatrix.sumRegion(1,1,2,2);
    numMatrix.sumRegion(1,2,2,4);
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */