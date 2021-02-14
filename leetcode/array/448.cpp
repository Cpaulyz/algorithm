// https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
// Created by admin on 2021/2/13.
// 原地修改，复用原数组，然后取模
using namespace std;
#include <vector>
#include <unordered_set>
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            nums[(nums[i]-1)%n]+=n;
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i]<=n){
                res.push_back(i+1);
            }
        }
        return res;
    }
};