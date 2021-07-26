// https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/
// Created by admin on 2021/7/26.
// 先转为最长公共子序列问题，再转为最长上升子序列问题，十分有意思！

using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> pos;
        for (int i = 0; i < target.size(); ++i) {
            pos[target[i]] = i;
        }
        vector<int> pos_arr;
        for (int n:arr){
            if(pos.count(n)!=0){
                pos_arr.push_back(pos[n]);
            }
        }
        // 对 pos_arr 计算最长上升子序列
        vector<int> dp(1,INT32_MIN); // dp[i]表示长度为i的上升子序列最小的最大值
        for(int n:pos_arr){
            // 寻找第一次大于n的下标，二分
            auto it = lower_bound(dp.begin(),dp.end(),n);
            if(it==dp.end()){
                dp.push_back(n);
            }else{
                *it = n;
            }
        }
        return target.size()-dp.size()+1;
    }
};