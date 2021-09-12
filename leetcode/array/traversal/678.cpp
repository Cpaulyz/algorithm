// https://leetcode-cn.com/problems/valid-parenthesis-string/
// Created by 陈彦泽 on 2021/9/12.
// 双向遍历模拟栈
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    bool checkValidString(string s) {
        int kuohao =0,star = 0;
        for (int i = 0; i < s.size(); ++i) { // 检查右括号
            if(s[i]=='('){
                kuohao++;
            }else if(s[i]=='*'){
                star++;
            }else if(s[i]==')'){
                if(kuohao > 0){
                    kuohao--;
                } else if(star>0){
                    star--;
                }else{
                    return false;
                }
            }
        }
        kuohao=star=0;
        for (int i = s.size()-1; i >=0; --i) { // 检查左括号
            if(s[i]==')'){
                kuohao++;
            }else if(s[i]=='*'){
                star++;
            }else if(s[i]=='('){
                if(kuohao > 0){
                    kuohao--;
                } else if(star>0){
                    star--;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};