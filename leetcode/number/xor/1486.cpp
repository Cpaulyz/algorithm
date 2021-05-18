// https://leetcode-cn.com/problems/xor-operation-in-an-array/
// Created by admin on 2021/5/7.
// 无脑遍历,简单

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = start;
        for(int i=1;i<n;++i){
            res = res^(start+2*i);
        }
        return res;
    }
};