// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
// Created by admin on 2021/2/25.
// 单调栈
using namespace std;

#include <vector>
#include <stack>

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(-1); // 哨兵，把全部出栈
        stack<int> s; // 底到顶，小到大单调栈
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while ((!s.empty()) && heights[s.top()] > heights[i]) {
                int tmp = s.top();
                s.pop();
                int left = s.empty() ? -1 : s.top();
                maxArea = max(maxArea, heights[tmp] * (i - left - 1));
            }
            s.push(i);
        }
        return maxArea;
    }
};

int main() {
    Solution s;
    vector<int> a{2, 1, 5, 6, 2, 3};
    s.largestRectangleArea(a);
}