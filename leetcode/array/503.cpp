// https://leetcode-cn.com/problems/next-greater-element-ii/
// Created by admin on 2021/3/6.
// 单调栈+两次循环
using namespace std;
#include <vector>
#include <stack>
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s; // 单调减
        vector<int> res(nums.size());
        // first loop
        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty()&&nums[s.top()]<nums[i]){
                int tmp = s.top();
                s.pop();
                res[tmp] = nums[i];
            }
            s.push(i);
        }
        // second loop
        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty()&&nums[s.top()]<nums[i]){
                int tmp = s.top();
                s.pop();
                res[tmp] = nums[i];
            }
        }
        // -1
        while (!s.empty()){
            int tmp = s.top();
            s.pop();
            res[tmp] = -1;
        }
        return res;
    }
};