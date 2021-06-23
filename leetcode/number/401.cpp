// https://leetcode-cn.com/problems/binary-watch/
// Created by admin on 2021/6/23.
// 本质上就是算1

using namespace  std;
#include <vector>
#include <string>

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if(count(i)+count(j)==turnedOn){
                    res.push_back(to_string(i)+":"+(j<10?"0":"")+to_string(j));
                }
            }
        }
        return res;
    }

    int count(int n) {
        int res = 0;
        while(n!=0){
            res++;
            n = n&(n-1);
        }
        return res;
    }
};