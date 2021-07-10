// https://leetcode-cn.com/problems/binary-subarrays-with-sum/
// Created by admin on 2021/7/8.
// 前缀和+哈希表


using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
hashc:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> preSum_cnt;
        preSum_cnt[0] = 1;
        int sum=0;
        int res=0;
        for (int n:nums){
            sum+=n;
            res += sum-goal>=0?preSum_cnt[sum-goal]:0;
            preSum_cnt[sum]++;
        }
        return res;
    }
};