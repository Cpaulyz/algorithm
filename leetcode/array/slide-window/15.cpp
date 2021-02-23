// https://leetcode-cn.com/problems/3sum/
// Created by admin on 2021/2/23.
//

using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3){
            return res;
        }
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if(i>0&&nums[i]==nums[i-1]){
                continue; // 去重
            }
            int target = 0-nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while (left<right){
                if(nums[left]+nums[right]==target){
                    res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    do{
                        left++;
                    }while (left<right&&nums[left]==nums[left-1]);
                }else if(nums[left]+nums[right]<target){
                    do{
                        left++;
                    }while (left<right&&nums[left]==nums[left-1]);
                }else{ // >
                    do{
                        right--;
                    }while (left<right&&nums[right]==nums[right+1]);
                }
            }
        }
        return res;
    }
};