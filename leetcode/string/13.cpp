// https://leetcode-cn.com/problems/roman-to-integer/submissions/
// Created by admin on 2021/5/15.
// 循环判断即可

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int prev = getValue(s[0]);
        for(int i = 1;i<s.size();++i){
            int tmp = getValue(s[i]);
            if(prev<tmp){
                res -= prev;
            }else{
                res += prev;
            }
            prev = tmp;
        }
        res += prev;
        return res;
    }

    int getValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};