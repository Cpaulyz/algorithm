// https://leetcode-cn.com/problems/jump-game/
// Created by admin on 2021/2/28.
// O(n) 直接贪心

using namespace std;
#include <vector>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(i>maxPos){
                return false;
            }
            maxPos = max(maxPos,i+nums[i]);
        }
        return true;
    }
};