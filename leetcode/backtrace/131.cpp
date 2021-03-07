// https://leetcode-cn.com/problems/palindrome-partitioning/
// Created by admin on 2021/3/7.
// 经典回溯，判断回文部分可以用dp优化
using namespace std;
#include <vector>
#include <string>

class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> set;
        backtrace(s,0,set);
        return res;
    }

    void backtrace(string &s, int start, vector<string> &set) {
        if (start == s.size()){
            res.push_back(vector<string>(set.begin(),set.end()));
        }
        for (int i = start; i < s.size(); ++i) {
            if(valid(s,start,i+1)){
                set.push_back(s.substr(start,i+1-start));
                backtrace(s,i+1,set);
                set.pop_back();
            }
        }
    }

    bool valid(string &s, int start, int end) {
        for (int i = 0; i <(end-start+1)/2; ++i) {
            if(s[start+i]!=s[end-1-i]){
                return false;
            }
        }
        return true;
    }
};