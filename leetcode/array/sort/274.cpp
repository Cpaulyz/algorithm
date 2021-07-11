// https://leetcode-cn.com/problems/h-index/
// Created by admin on 2021/7/11.
// 排序就完事，最求极致可以用计数排序


using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(),citations.rend());
        int i;
        for (i = 0; i < citations.size(); ++i) {
            if(citations[i]<i+1){
                break;
            }
        }
        return i-1;
    }
};