// https://leetcode-cn.com/problems/ugly-number/
// Created by admin on 2021/4/11.
// 简单，循环遍历即可

class Solution {
public:
    bool isUgly(int n) {
        while(n>5){
            if(n%2==0){
                n=n/2;
            }else if(n%5==0){
                n=n/5;
            }else if(n%3==0){
                n=n/3;
            }else{
                return false;
            }
        }
        return n>0;
    }
};