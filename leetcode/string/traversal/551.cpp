// https://leetcode-cn.com/problems/student-attendance-record-i/
// Created by 陈彦泽 on 2021/8/17.
// 简单遍历即可

using namespace std;
#include <string>

class Solution {
public:
    bool checkRecord(string s) {
        int l = 0;
        int a = 0;
        for(int i=0;i<s.size();++i){
            switch (s[i]) {
                case 'L':
                    l++;
                    if(l==3){
                        return false;
                    }
                    break;
                case 'A':
                    a++;
                    if(a==2){
                        return false;
                    }
                default:
                    l=0;
            }
        }
        return true;
    }
};