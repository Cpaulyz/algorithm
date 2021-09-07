// https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/
// Created by 陈彦泽 on 2021/9/7.
// 一次遍历贪心

class Solution {
public:
    int balancedStringSplit(string s) {
        // 贪心
        int res=0 ,l=0, r=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='L'){
                l++;
            }else if(s[i]=='R'){
                r++;
            }
            if(l==r){
                res++;
                l=r=0;
            }
        }
        return res;
    }
};