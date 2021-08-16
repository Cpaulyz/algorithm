// https://leetcode-cn.com/problems/beautiful-arrangement/
// Created by admin on 2021/8/16.
// 观察到题目给的范围比较小（15），直接暴力回溯即可！

using namespace std;

#include <vector>
#include <algorithm>

class Solution {
    int res = 0;
public:
    int countArrangement(int n) {
        vector<bool> used(n+1,false);
        backtrace(used,1,n);
        return res;
    }

    void backtrace(vector<bool> &used,int slot,int n){
        if(slot>n){
            res++;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if(used[i]==false&&(i%slot==0||slot%i==0)){
                used[i] = true;
                backtrace(used,slot+1,n);
                used[i] = false;
            }
        }
    }
};