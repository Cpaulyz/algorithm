//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
// Created by admin on 2021/4/18.
// 快慢双指针

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int slowPtr=0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=nums[slowPtr]){
                nums[slowPtr+1]=nums[i];
                slowPtr++;
            }
        }
        return slowPtr+1;
    }
};