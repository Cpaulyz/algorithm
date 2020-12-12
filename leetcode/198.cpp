// https://leetcode-cn.com/problems/house-robber/
// Created by admin on 2020/12/12.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }else if(nums.size()==1){
            return nums[0];
        }else if(nums.size()==2){
            return max(nums[0],nums[1]);
        }else{
            vector<int> dp;
            dp.push_back(nums[0]);
            dp.push_back(max(nums[0],nums[1]));
            for (int i = 2; i < nums.size(); ++i) {
                dp.push_back(max(dp[i-1],dp[i-2]+nums[i]));
            }
            return dp[nums.size()-1];
        }
    }
};

int main(){
    vector<int> a{2};
    Solution s;
    cout << s.rob(a);
}