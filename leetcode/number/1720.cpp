// https://leetcode-cn.com/problems/decode-xored-array/
// Created by admin on 2021/5/6.
// 遍历异或,简单题

using namespace std;
#include <vector>

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res{first};
        for(int e:encoded){
            res.push_back(res.back()^e);
        }
        return res;
    }
};