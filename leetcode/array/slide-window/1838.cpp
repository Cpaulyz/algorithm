// https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element/
// Created by admin on 2021/7/19.
// 滑窗

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        if(nums.size()==1){
            return 1;
        }
        sort(nums.begin(),nums.end());
        int left=0,right=1;
        long increment = 0;
        int res=0;
        for(int right=1;right<nums.size();++right){
            // add right to set
            increment += ((long)right-left)*(nums[right]-nums[right-1]);
            while(increment>k){
                increment-=(nums[right]-nums[left++]);
            }
            res = max(res,right-left+1);
        }
        return res;
    }
};