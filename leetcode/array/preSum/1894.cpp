// https://leetcode-cn.com/problems/find-the-student-that-will-replace-the-chalk/
// Created by 陈彦泽 on 2021/9/10.
// 前缀和+二分

using namespace std;
#include <vector>
#include <algorithm>


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<int> preSum;
        int sum = 0;
        for (int i = 0; i < chalk.size(); ++i) {
            sum += chalk[i];
            if(sum>k){
                return i;
            }else{

                preSum.push_back(sum);
            }
        }
        k = k % sum;
        int pos = upper_bound(preSum.begin(),preSum.end(),k)-preSum.begin();
        return pos;
    }
};