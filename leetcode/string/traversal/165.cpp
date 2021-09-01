// https://leetcode-cn.com/problems/compare-version-numbers/
// Created by 陈彦泽 on 2021/9/1.
// 遍历比较
using namespace std;

#include <string>

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1,v2;
        int ptr1 = 0,ptr2 = 0;

        while (ptr1<version1.size()||ptr2<version2.size()){
            v1 = v2 = 0;
            while(ptr1 < version1.size()){
                char c = version1[ptr1++];
                if(c=='.'){
                    break;
                }else{
                    v1 = v1*10 + c-'0';
                }
            }
            while(ptr2 < version2.size()){
                char c = version2[ptr2++];
                if(c=='.'){
                    break;
                }else{
                    v2 = v2*10 + c-'0';
                }
            }
            if(v1<v2){
                return -1;
            }else if(v1>v2){
                return 1;
            }
        }
        return 0;
    }
};