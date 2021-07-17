// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
// Created by admin on 2021/7/17.
// 遍历前缀和

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -9999;
        int preSum = 0;
        for(int n:nums){
            preSum+=n;
            if(preSum>res){
                res = preSum;
            }
            if(preSum<0){
                preSum=0;
            }
        }
        return res;
    }
};