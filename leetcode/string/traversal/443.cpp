// https://leetcode-cn.com/problems/string-compression/
// Created by admin on 2021/8/21.
// 快慢双指针

using namespace std;
#include <vector>
#include <string>


class Solution {
public:
    int compress(vector<char>& chars) {
        char curr = chars[0];
        int slowPtr = 0;
        int count = 1;
        for (int fastPtr = 1; fastPtr < chars.size(); ++fastPtr) {
            if(chars[fastPtr]==curr){
                count++;
            }else{
                chars[slowPtr++] = curr;
                curr = chars[fastPtr];
                if(count>1){
                    string tmp = to_string(count);
                    for (int i = 0; i < tmp.size(); ++i) {
                        chars[slowPtr++] = tmp[i];
                    }
                }
                count = 1;
            }
        }
        chars[slowPtr++] = curr;
        if(count>1){
            string tmp = to_string(count);
            for (int i = 0; i < tmp.size(); ++i) {
                chars[slowPtr++] = tmp[i];
            }
        }
        return slowPtr;
    }
};