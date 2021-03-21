// https://leetcode-cn.com/problems/generate-parentheses/
// Created by admin on 2021/3/21.
// 回溯
using namespace std;
#include <string>
#include <vector>

class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        backtrace("(",n-1,n);
        return res;
    }
    void backtrace(string s,int left,int right){
        if(left==0&&right==0){
            res.push_back(s);
        }else{
            if(left>0){
                backtrace(s+"(",left-1,right);
            }
            if(right>0&&right>left){
                backtrace(s+")",left,right-1);
            }
        }
    }
};