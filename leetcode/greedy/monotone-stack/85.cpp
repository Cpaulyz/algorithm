// https://leetcode-cn.com/problems/maximal-rectangle/
// Created by admin on 2021/2/25.
// 单调栈，84拓展题
using namespace std;

#include <vector>
#include <stack>

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        int maxArea = 0;
        vector<int> heights(matrix[0].size());
        // 求出每个元素对应的高度，这个高度就是每一行往上看对应的连续1的长度
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j]==0){
                    heights[j] = 0;
                }else{
                    heights[j] +=1;
                }
            }
            maxArea = max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }

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
        heights.pop_back();
        return maxArea;
    }
};

int main(){
    vector<vector<char>> v;
    v.push_back({'1'});
    Solution s;
    s.maximalRectangle(v);

}