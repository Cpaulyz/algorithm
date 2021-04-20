// https://leetcode-cn.com/problems/remove-element/submissions/
// Created by admin on 2021/4/20.
// 快慢双指针

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowPtr=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==val){
                continue;
            }else{
                nums[slowPtr++]=nums[i];
            }
        }
        return slowPtr;
    }
};