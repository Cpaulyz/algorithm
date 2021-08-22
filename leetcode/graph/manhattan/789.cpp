// https://leetcode-cn.com/problems/escape-the-ghosts/
// Created by admin on 2021/8/22.
// 曼哈顿距离

using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dest = abs(target[0]) + abs(target[1]);
        for (int i = 0; i < ghosts.size(); ++i) {
            int tmp =  abs(ghosts[i][0]-target[0]) + abs(ghosts[i][1]-target[1]);
            if(tmp<=dest){
                return false;
            }
        }
        return true;
    }
};