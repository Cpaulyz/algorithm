// https://leetcode-cn.com/problems/excel-sheet-column-title/
// Created by admin on 2021/6/29.
// 1开始的26进制

using namespace std;

#include <string>

class Solution {
public:
    string convertToTitle(int columnNumber) {
        // 26进制
        // 26:Z
        // 25:Y
        // 27:AB
        string res = "";
        while(columnNumber>0){
            columnNumber--; // 因为从1开始，要改成从0开始
            int tmp = columnNumber%26;
            columnNumber = columnNumber/26;
            res = string(1,'A'+tmp)+res;
        }
        return res;
    }
};