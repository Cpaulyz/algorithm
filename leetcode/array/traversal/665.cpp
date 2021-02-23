// https://leetcode-cn.com/problems/non-decreasing-array/
// Created by admin on 2021/2/7.
// 遍历，修改

using namespace std;
#include <vector>


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            if(nums[i]>nums[i+1]){
                if(cnt!=0){
                    return false;
                }
                // let nums[i] = nums[i+1]
                if(i==0){
                    nums[i] = nums[i+1];
                    cnt++;
                }else if(nums[i-1]<=nums[i+1]){
                    nums[i] = nums[i+1];
                    cnt++;
                }else{
                    nums[i+1] = nums[i];
                    cnt++;
                }
            }
        }
        return true;
    }
};