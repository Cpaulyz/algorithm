// https://leetcode-cn.com/problems/integer-to-roman/
// Created by admin on 2021/5/14.
// 解码即可

using namespace std;
#include <string>

class Solution {
public:
    string intToRoman(int num) {
        string res ="";
        int arr[]{900,500,400,100,90,50,40,10,9,5,4,1};
        string str[]{"CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        while (num>1000){
            res += "M";
            num -= 1000;
        }
        for (int i = 0; i < 12; ++i) {
            while (num>arr[i]){
                res += str[i];
                num-=arr[i];
            }
        }
        return res;

    }
};