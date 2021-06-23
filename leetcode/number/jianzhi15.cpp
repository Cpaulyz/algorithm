// https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
// Created by admin on 2021/6/23.
// 位运算，O(1的个数)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n!=0){
            res++;
            n = n&(n-1);
        }
        return res;
    }
};