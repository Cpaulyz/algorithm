// https://leetcode.cn/problems/largest-merge-of-two-strings/
// Created by 陈彦泽 on 2022/12/24.
// 贪心，主要学到的是字符串比较是字典序
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int index1 = 0;
        int index2 = 0;
        string res = "";
        while (index1<word1.length()||index2<word2.length()){
            if(word1.substr(index1)>word2.substr(index2)){
                res += word1[index1++];
            }else {
                res += word2[index2++];
            }
        }
        if(index1<word1.length()){
            res+=word1.substr(index1);
        }else if(index2<word2.length()){
            res+=word2.substr(index2);
        }
        return res;
    }
};

int main(){
    Solution s;
    s.largestMerge("cabaa","bcaaa");
}