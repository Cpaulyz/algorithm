// https://leetcode-cn.com/problems/hamming-distance/
// Created by admin on 2021/5/27.
// 异或遍历 水题

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res=0;
        for(int i=0;i<32;++i){
            if(((x^y)&(1<<i))!=0){
                res++;
            }
        }
        return res;
    }
};