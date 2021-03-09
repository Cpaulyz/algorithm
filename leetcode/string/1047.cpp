//https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
// Created by admin on 2021/3/9.
// 栈操作
using namespace std;
#include <string>
#include <deque>

class Solution {
public:
    string removeDuplicates(string S) {
        deque<char> s;
        for (int i = 0; i < S.size(); ++i) {
            if(s.empty()||s.back()!=S[i]){
                s.push_back(S[i]);
            }else{
                s.pop_back();
            }
        }
        string  res = "";
        while (!s.empty()){
            res += s.front();
            s.pop_front();
        }
        return res;
    }
};