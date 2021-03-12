// https://leetcode-cn.com/problems/zigzag-conversion/
// Created by admin on 2021/3/12.
//
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        string res = "";
        int group = numRows+numRows-2;
        for (int i = 0; i <numRows; ++i) {
            for (int j = 0; j < s.size(); j+=group) {
                if(i==0||i==numRows-1){
                    if(j+i<s.size())
                        res+=s[j+i];
                }else {
                    if(j+i<s.size())
                        res += s[j + i];
                    if(j+2*numRows-2-i<s.size())
                        res += s[j+2*numRows-2-i];
                }
            }
        }
        return res;
    }
};