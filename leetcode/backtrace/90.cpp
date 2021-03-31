// https://leetcode-cn.com/problems/subsets-ii/
// Created by admin on 2021/3/31.
// 回溯，关键在于去重
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        res.push_back({}); // 空集
        vector<bool> used(nums.size());
        backtrace(nums,tmp,used,0);
        return res;
    }

    void backtrace(vector<int>& nums,vector<int>& tmp,vector<bool>& used,int index){
        if(index==nums.size()){
            return;
        }else{
            if(index>0&&nums[index]==nums[index-1]&&used[index-1]==false){
                // 去重
            }else{
                tmp.push_back(nums[index]);
                used[index]=true;
                res.push_back(tmp);
                backtrace(nums,tmp,used,index+1);
                used[index]=false;
                tmp.pop_back();
            }
            backtrace(nums,tmp,used,index+1);
        }
    }
};