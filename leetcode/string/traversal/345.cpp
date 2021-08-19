// https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
// Created by 陈彦泽 on 2021/8/19.
// 原地修改，双指针双向遍历
using namespace std;
#include <string>

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0,right = s.size()-1;
        bool leftScan = false;
        while (left<right){
            for (; left < s.size(); left++) {
                if(isVovel(s[left])){
                    break;
                }
            }
            for(;right>=0;right--){
                if(isVovel(s[right])){
                    break;
                }
            }
            if(left<right){
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                left++;right--;
            }
        }
        return s;
    }

    bool isVovel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
        c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
};