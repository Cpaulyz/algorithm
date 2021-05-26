// https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Created by admin on 2021/5/26.
// 括号处理+模拟

using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>


class Solution {
    unordered_map<int,int> kuohao;
public:
    string reverseParentheses(string s) {
        // (a(bc)(de)f)
        stack<int> tmp;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                tmp.push(i);
            }else if(s[i]==')'){
                kuohao[tmp.top()] = i;
                tmp.pop();
            }
        }
        return helper(s,0,s.size()-1, false);
    }

    string helper(string& s,int left,int right,bool reverse){
        string res="";
        int index = left;
        while(index<=right){
            if(s[index]=='('){
                if(!reverse)
                    res += helper(s,index+1,kuohao[index]-1,!reverse);
                else
                    res = helper(s,index+1,kuohao[index]-1,!reverse) + res;
                index=kuohao[index]+1;
            }else{
                if(!reverse)
                    res += s[index];
                else
                    res = s[index] + res;
                index++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.reverseParentheses("a(bcdefghijkl(mno)p)q");
}