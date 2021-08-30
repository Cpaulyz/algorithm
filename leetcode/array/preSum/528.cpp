// https://leetcode-cn.com/problems/random-pick-with-weight/
// Created by 陈彦泽 on 2021/8/30.
// 其实用的是表驱动的思想，在实现上是前缀和+二分查找
// 值得学习的：
// 1、 随机数的生成
// 2、 二分查找的轮子
using namespace std;

#include <string>
#include <algorithm>
#include <queue>
#include <vector>
class Solution {
    vector<int> preSum;
    int total;
public:
    Solution(vector<int>& w) {
        int tmp = 0;
        for(int n:w){
            tmp+=n;
            preSum.push_back(tmp);
        }
        total = tmp;
    }

    int pickIndex() {
        int n = rand()%total; // 生成随机数
        // cout << n << endl;
        return upper_bound(preSum.begin(),preSum.end(),n)-preSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */