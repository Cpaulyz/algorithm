// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
// Created by 陈彦泽 on 2022/12/13.
// 回溯
using namespace std;
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
    unordered_map<char,string> map = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string s;
        if(digits.size()>0){
            traceback(res,digits,0,s);
        }
        return res;
    }

    void traceback(vector<string>& res, string digits, int index, string& s){
        if(index==digits.size()){
            res.push_back(s);
            return;
        }
        for(char c:map[digits[index]]){
            s+=c;
            traceback(res,digits,index+1,s);
            s = s.substr(0,s.size()-1);
        }
    }
};

int main(){
    Solution s;
    s.letterCombinations("23");
}