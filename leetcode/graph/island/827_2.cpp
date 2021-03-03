// https://leetcode-cn.com/problems/making-a-large-island/
// Created by admin on 2021/3/3.
// DFS解法

using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
    unordered_map<int,int> map;
    int maxArea = 0;
public:
    int largestIsland(vector<vector<int>>& grid) {
        getAreaOfIsland(grid);
        vector<int> tmp;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]==0){
                    int tmpArea = 1;
                    tmp.push_back(j==0?0:grid[i][j-1]);
                    tmp.push_back(j==grid[0].size()-1?0:grid[i][j+1]);
                    tmp.push_back(i==0?0:grid[i-1][j]);
                    tmp.push_back(i==grid.size()-1?0:grid[i+1][j]);
                    sort(tmp.begin(),tmp.end());
                    while (!tmp.empty()){
                        int a = tmp.back();
                        tmp.pop_back();
                        if(a!=0&&(tmp.empty()||a!=tmp.back())){
                            tmpArea+=map[a];
                        }
                    }
                    maxArea = max(maxArea,tmpArea);
                }
            }
        }
        return maxArea;
    }
    void getAreaOfIsland(vector<vector<int>>& grid) {
        int index = 2;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]==1) {
                    int area = dfs(grid, i, j,index);
                    maxArea = max(maxArea,area);
                    map[index++] = area;
                }
            }
        }
    }
    int dfs(vector<vector<int>>& grid,int row,int col,int index){
        if(row<0||col<0||row>=grid.size()||col>=grid[0].size()||grid[row][col]!=1){
            return 0;
        }
        grid[row][col] = index;
        return 1+dfs(grid,row-1,col,index)+dfs(grid,row,col-1,index)
        +dfs(grid,row+1,col,index)+dfs(grid,row,col+1,index);
    }
};


int main(){
    Solution s;
    vector<vector<int>> v;
    v.push_back({0,0,0,0,0,0,0});
    v.push_back({0,1,1,1,1,0,0});
    v.push_back({0,1,0,0,1,0,0});
    v.push_back({1,0,1,0,1,0,0});
    v.push_back({0,1,0,0,1,0,0});
    v.push_back({0,1,0,0,1,0,0});
    v.push_back({0,1,1,1,1,0,0});
    s.largestIsland(v);
}