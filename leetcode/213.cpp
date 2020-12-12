// https://leetcode-cn.com/problems/house-robber-ii/
// Created by admin on 2020/12/12.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }else if(nums.size()==2) {
            return max(nums[0], nums[1]);
        }else if(nums.size()==3){
            return max(max(nums[0],nums[1]),nums[2]);
        }else{
            vector<vector<int>> dp; // 第0是不包含第一个的，第1是包含第一个的
            dp.push_back({0,nums[0]});
            dp.push_back({nums[1],nums[0]});
            dp.push_back({max(nums[1],nums[2]),nums[0]});
            for (int i = 3; i < nums.size(); ++i) {
                int b = max(dp[i-2][1]+nums[i-1],dp[i-1][1]);
                int a = max(dp[i-1][0],dp[i-2][0]+nums[i]);
                dp.push_back({a,b});
            }
            return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
        }
    }
};

int main(){
    vector<int> a{200,3,140,20,10};
    Solution s;
    cout << s.rob(a);
}

