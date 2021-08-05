// https://leetcode-cn.com/problems/find-eventual-safe-states/
// Created by admin on 2021/8/5.
// 反向拓扑排序 https://leetcode-cn.com/problems/find-eventual-safe-states/solution/gtalgorithm-san-ju-hua-jiao-ni-wan-zhuan-xf5o/
// 1. 如果一个点没有出度，则是安全的点
// 2. 如果一个点指向的点全是安全点，则是安全的点
// 3. 因此，将图进行反向，进行拓扑排序即可

using namespace std;

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        vector <vector<int>> graphSet(graph.size(), vector<int>());
        vector<int> count(graph.size(), 0); // 入度
        // build graph
        for (int i = 0; i < graph.size(); ++i) {
            for (int src:graph[i]) {
                graphSet[src].push_back(i);
                count[i]++;
            }

        }
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < count.size(); ++i) {
            if (count[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            for (int tar:graphSet[n]) {
                count[tar]--;
                if (count[tar] == 0) {
                    q.push(tar);
                }
            }
        }
        for (int i = 0; i < count.size(); ++i) {
            if(count[i]==0){
                res.push_back(i);
            }
        }
        return res;
    }
};