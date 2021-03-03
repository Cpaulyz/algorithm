// https://leetcode-cn.com/problems/counting-bits/
// Created by admin on 2021/3/3.
// 重点在于dp解法，观察最高位1
// 1. 出现新高的话，1的个数必定为1
// 2. 若没有出现新高，1的个数可以等于前面某个+1
using namespace std;
#include <vector>

class Solution {
public:
    // dp解法
    // 00001
    // 00010
    // 00011
    // 00100
    // 00101
    // 00110
    // 00111
    // 01000
    vector<int> countBits(int num) {
        vector<int> res;
        int high = 0;
        int offset = 1;
        res.push_back(0);
        for (int i = 1; i <= num; ++i) {
            // count
            if((i&(1<<high))!=0){ // 新的高位1出现
                offset = 1<<high;
                high++;
                res.push_back(1);
            }else{
                res.push_back(1+res[i-offset]);
            }
        }
        return res;
    }

    // 朴素解法
//    vector<int> countBits(int num) {
//        vector<int> res;
//        for (int i = 0; i <= num; ++i) {
//            // count
//            int x = i;
//            int cnt = 0;
//            while (x!=0) {
//                x = x & (x - 1); // 每次会少掉最右边的0
//                cnt++;
//            }
//            res.push_back(cnt);
//        }
//        return res;
//    }
};