// https://leetcode-cn.com/problems/minimum-falling-path-sum/
// Created by admin on 2021/2/26.
// dp+复用原数组
using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        if(matrix.size()==1){
            return matrix[0][0];
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (j == 0) {
                    matrix[i][j] = (min(matrix[i-1][j], matrix[i-1][j + 1]) + matrix[i][j]);
                } else if (j == matrix[0].size() - 1) {
                    matrix[i][j] =(min(matrix[i-1][j], matrix[i-1][j - 1]) + matrix[i][j]);
                } else {
                    matrix[i][j] = (min(min(matrix[i-1][j - 1], matrix[i-1][j]), matrix[i-1][j + 1]) + matrix[i][j]);
                }
            }
        }
        int minFall = 9999;
        for(int a:matrix[matrix.size()-1]){
            if(a<minFall){
                minFall = a;
            }
        }
        return minFall;
    }
};
int main(){
    Solution s;
    vector<vector<int>> v;
    v.push_back({2,1,3});
    v.push_back({6,5,4});
    v.push_back({7,8,9});
    s.minFallingPathSum(v);
}