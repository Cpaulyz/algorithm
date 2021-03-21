// https://leetcode-cn.com/problems/first-missing-positive/
// Created by admin on 2021/3/21.
// 原数组置换，练习降低空间、时间复杂度的好题！

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            if(nums[i]==i+1){
                continue;
            }else if(nums[i]>nums.size()||nums[i]<=0){
                continue;
            }else{
                int tmp = nums[i];
                nums[i] = -1;
                while(true){
                    int n  = nums[tmp-1];
                    nums[tmp-1] = tmp;
                    tmp = n;
                    if(tmp>nums.size()||tmp<=0||nums[tmp-1]==tmp){
                        break;
                    }
                }
            }
        }
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};