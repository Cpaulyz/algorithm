// https://leetcode-cn.com/problems/island-perimeter/
// Created by admin on 2021/3/2.
// 直接遍历即可？？？

using namespace std;

#include <vector>

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int up = i == 0 ? 0 : grid[i - 1][j];
                int left = j == 0 ? 0 : grid[i][j - 1];
                if(grid[i][j]==1){
                    if(up==0) cnt++;
                    if(left==0) cnt++;
                    if(i==grid.size()-1) cnt++; // 最底下
                    if(j==grid[0].size()-1) cnt++; // 最右边
                }else{
                    if(up==1) cnt++;
                    if(left==1) cnt++;
                }
            }
        }
        return cnt;
    }
};