// https://leetcode-cn.com/problems/sum-of-square-numbers/
// Created by admin on 2021/4/29.
// https://leetcode-cn.com/problems/sum-of-square-numbers/solution/shuang-zhi-zhen-de-ben-zhi-er-wei-ju-zhe-ebn3/

using namespace std;
#include <math.h>

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; i < sqrt(c); ++i) {
            int tmp = c-i*i;
            if((int)sqrt(tmp)*(int)sqrt(tmp)==tmp){
                return true;
            }
        }
        return false;
    }
};