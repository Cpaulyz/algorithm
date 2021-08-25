// https://leetcode-cn.com/problems/all-paths-from-source-to-target/
// Created by 陈彦泽 on 2021/8/25.
// dfs暴搜

using namespace std;
#include <vector>

class Solution {
    vector<vector<int>> res;
    vector<int> curr;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res = vector<vector<int>>();
        curr = vector<int>();
        curr.push_back(0);
        dfs(graph,0);
        return res;
    }

    void dfs(vector<vector<int>>& graph,int now){
        for(int nxt:graph[now]){
            curr.push_back(nxt);
            if(nxt== graph.size()-1){
                res.push_back(curr);
            }else{
                dfs(graph,nxt);
            }
            curr.pop_back();
        }
    }
};