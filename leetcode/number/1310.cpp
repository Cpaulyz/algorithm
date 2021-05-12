// https://leetcode-cn.com/problems/xor-queries-of-a-subarray/
// Created by admin on 2021/5/12.
// 记忆化搜索

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        vector<int> helper; // 记忆化搜索
        int prev = 0;
        for(int n:arr){
            helper.push_back(prev);
            prev ^= n;
        }
        helper.push_back(prev);
        for(auto q:queries){
            res.push_back(helper[q[1]+1]^helper[q[0]]);
        }
        return res;
    }
};