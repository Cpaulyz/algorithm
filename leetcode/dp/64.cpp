// https://leetcode-cn.com/problems/minimum-path-sum/
// Created by admin on 2020/12/21.
//

#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> prev;
        for (int i = 0; i < grid[0].size(); ++i) {
            if(i==0){
                prev.push_back(grid[0][0]);
            }else{
                prev.push_back(grid[0][i]+prev[i-1]);
            }
        }
        for (int i = 1; i < grid.size(); ++i) {
            vector<int> tmp;
            for (int j = 0; j < grid[0].size(); ++j) {
                if(j==0){
                    tmp.push_back(prev[j]+grid[i][j]);
                }else{
                    tmp.push_back(min(tmp[j-1],prev[j])+grid[i][j]);
                }
            }
            prev = tmp;
        }
        return prev[grid[0].size()-1];
    }
};