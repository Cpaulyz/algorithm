// https://leetcode-cn.com/problems/check-if-all-the-integers-in-a-range-are-covered/
// Created by admin on 2021/7/23.
// 考虑到范围有限，直接暴力哈希即可

using namespace std;
#include <vector>
#include <unordered_set>
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_set<int> set;
        for(auto range:ranges){
            for (int i = range[0]; i <=range[1] ; ++i) {
                set.insert(i);
            }
        }
        for (int i = left; i <= right; ++i) {
            if(set.count(i)==0){
                return false;
            }
        }
        return true;
    }
};