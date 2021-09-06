// https://leetcode-cn.com/problems/implement-rand10-using-rand7/
// Created by 陈彦泽 on 2021/9/6.
// 七进制

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // create num
        int tmp = (rand7()-1) + (rand7()-1)*7;
        while(tmp>9){
            tmp = (rand7()-1) + (rand7()-1)*7;
        }
        return tmp +1;
    }
};