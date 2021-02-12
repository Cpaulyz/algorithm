// https://leetcode-cn.com/problems/pascals-triangle-ii/
// Created by admin on 2021/2/12.
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1

using namespace std;
#include <vector>

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        for (int i = 0; i < rowIndex+1; ++i) {
            for (int j = i-1; j >0 ; --j) {
                res[j] = res[j] + res[j-1];
            }
            res[i] = 1;
        }
        return res;
    }
};