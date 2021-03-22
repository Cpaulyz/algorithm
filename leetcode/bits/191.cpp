// https://leetcode-cn.com/problems/number-of-1-bits/
// Created by admin on 2021/3/22.
//
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n!=0){
            n = n&(n-1);
            res++;
        }
        return res;
    }
};