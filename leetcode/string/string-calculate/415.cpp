// https://leetcode-cn.com/problems/add-strings/
// Created by admin on 2021/2/1.
// 高精度求和，字符串相加
using namespace std;
#include <string>

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int len1 = num1.size(),len2=num2.size();
        if(len1<len2){ // 保证len1>=len2
            int tmp = len2;
            len2 = len1;
            len1 = tmp;
            string tmps = num2;
            num2 = num1;
            num1 = tmps;
        }
        string res = "";
        for (int i = 0; i < len2; ++i) {
            int tmp = num1.at(len1-1-i)+num2.at(len2-1-i)-'0'-'0'+carry;
            carry = 0;
            while (tmp>10){
                tmp = tmp-10;
                carry+=1;
            }
            res = to_string(tmp) + res;
        }
        for (int i = 0; i < len1 - len2; ++i) {
            int tmp = num1.at(len1-len2-1-i)-'0'+carry;
            carry = 0;
            while (tmp>10){
                tmp = tmp-10;
                carry+=1;
            }
            res = to_string(tmp) + res;
        }
        if(carry!=0){
            res = to_string(carry) + res;
        }
        return res;
    }
};