// https://leetcode-cn.com/problems/permutations-ii/
// Created by admin on 2021/3/22.
// 排序+回溯，因为原数组有重复，需要排序后判断是否可进入回溯

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        vector<int> used(nums.size(),0);
        backtrace(used,nums,curr);
        return res;
    }
    void backtrace(vector<int>& used,vector<int>&nums,vector<int>& curr){
        // finish
        bool finish = true;
        for(int i=0;i<used.size();++i){
            if(used[i]==0){
                if(i>0&&nums[i]==nums[i-1]&&used[i-1]==0){
                    continue;
                }else{
                    used[i]=1;
                    curr.push_back(nums[i]);
                    backtrace(used,nums,curr);
                    used[i]=0;
                    curr.pop_back();
                }
                finish = false;
            }
        }
        if(finish){
            res.push_back(curr);
        }
    }
};