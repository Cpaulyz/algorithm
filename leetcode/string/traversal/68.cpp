// https://leetcode-cn.com/problems/text-justification/
// Created by 陈彦泽 on 2021/9/9.
// 贪心遍历模拟
using namespace std;
#include <string>
#include <vector>


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> line;
        int lineLen = 0;
        for(string word:words){
            if(word.size()+lineLen+line.size()>maxWidth){
                string tmp = "";
                // print
                if(line.size()>1){
                    int blank = maxWidth - lineLen;
                    // split to line.size()-1
                    int avg = blank / (line.size()-1);
                    // x + y = sz
                    // x*(avg+1) + y*avg = blank
                    // sz*avg + x = blank
                    int x = blank-avg*(line.size()-1);
                    int y = line.size()-1-x;
                    string split  = "";
                    for (int i = 0; i < avg; ++i) {
                        split+=" ";
                    }
                    for (int i = 0; i < x; ++i) {
                        tmp += line[i];
                        tmp += split+" ";
                    }
                    for (int i = 0; i < y; ++i) {
                        tmp += line[x+i];
                        tmp += split;
                    }
                    tmp += line[line.size()-1];
                }else{
                    tmp += line[0];
                    while(tmp.size()<maxWidth){
                        tmp += " ";
                    }
                }
                res.push_back(tmp);
                line.clear();
                lineLen = 0;
            }
            line.push_back(word);
            lineLen += word.size();
        }
        string tmp = line[0];
        for (int i = 1; i < line.size(); ++i) {
            tmp += " ";
            tmp += line[i];
        }
        while(tmp.size()<maxWidth){
            tmp += " ";
        }
        res.push_back(tmp);
        return res;
    }
};