// https://leetcode-cn.com/problems/shortest-path-visiting-all-nodes/
// Created by admin on 2021/8/6.
// 状态压缩+bfs，状态压缩很难想是重点

using namespace std;

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <tuple>

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        // idx: 当前位置
        // status: 当前状态
        // dist: 当前路径长
        queue<tuple<int,int,int>> idx_status_dist;
        vector<unordered_map<int,bool>> visited(n,unordered_map<int,bool>()); // 是否访问过
        // init
        for (int i = 0; i < n; ++i) {
            int status = (1<<i);
            idx_status_dist.push({i,status,0});
            visited[i][status] = true;
        }
        // loop
        while (!idx_status_dist.empty()){
            auto [idx,status,dist] = idx_status_dist.front();
            idx_status_dist.pop();
            // cout <<"idx: "<< idx<< " loop: "<< bitset<sizeof(int)*4>(status) << " dist: "<<dist <<endl;
            if(status+1==(1<<n)){
                return dist;
            }
            for(int tar:graph[idx]){
                int nxtStatus = (status | (1<<tar));
                // 避免重复访问死循环
                if(!visited[tar][nxtStatus]){
                    visited[tar][nxtStatus] = true;
                    idx_status_dist.push({tar,nxtStatus,dist+1});
                }
            }
        }
        return -1;
    }
};