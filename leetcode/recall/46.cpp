// https://leetcode-cn.com/problems/permutations/
// Created by admin on 2021/3/6.
// 回溯
using namespace std;
#include <vector>

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> a;
        recall(nums,a);
        return res;
    }

    void recall(vector<int>& nums,vector<int>& memo){
        if(memo.size()==nums.size()){
            vector<int> tmp(memo.begin(),memo.end());
            res.push_back(tmp);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i]!=-9999){
                memo.push_back(nums[i]);
                int tmp = nums[i];
                nums[i] = -9999;
                recall(nums,memo);
                memo.pop_back();
                nums[i] = tmp;
            }
        }
    }
};