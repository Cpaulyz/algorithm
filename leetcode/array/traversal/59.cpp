// https://leetcode-cn.com/problems/spiral-matrix-ii/
// Created by admin on 2021/3/16.
//
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int right = n-1,down = n-1;
        int left = 0,up=0;
        int cnt = 1;
        int i=0,j=0;
        while (cnt<=n*n){
            for (i=up,j = left; j <=right; ++j) {
                res[i][j] = cnt++;
            }
            up++;
            for (j=right,i = up; i <= down ; ++i) {
                res[i][j] = cnt++;
            }
            right--;
            for (i=down,j = right; j >=left; --j) {
                res[i][j] = cnt++;
            }
            down--;
            for (j=left,i=down;i>=up;--i){
                res[i][j] = cnt++;
            }
            left++;
        }
        return res;
    }
};