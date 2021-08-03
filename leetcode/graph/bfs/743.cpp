// https://leetcode-cn.com/problems/network-delay-time/
// Created by admin on 2021/8/3.
// dijkstra

using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>
class Solution {
    int INF =101;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph(n+1,vector<int>(n+1,INF));
        // build graph
        for(auto time:times){
            graph[time[0]][time[1]] = time[2];
        }
        vector<bool> found(n+1,false);
        vector<int> distance(n+1,INF);
        found[k] = true;
        distance[k] = 0;
        // init
        int minDistance = INF;
        int minIdx = -1;
        for (int i = 1; i <= n; ++i) {
            distance[i] = min(graph[k][i],distance[i]);
            cout << distance[i] << " ";
            // find record
            if(distance[i]<minDistance&&!found[i]){
                minDistance = distance[i];
                minIdx = i;
            }
        }
        cout << endl;
        for (int loop = 0; loop < n - 1; ++loop) {
            if(minIdx==-1){
                break;
            }
            int minDistanceTmp = INF;
            int minIdxTmp = -1;
            found[minIdx] = true;
            cout << minIdx << ": ";
            for (int i = 1; i <= n; ++i) {
                distance[i] = min(distance[minIdx]+graph[minIdx][i],distance[i]);
                cout << distance[i] << " ";
                // find record
                if(distance[i]<minDistanceTmp&&!found[i]){
                    minDistanceTmp = distance[i];
                    minIdxTmp = i;
                }
            }
            cout << endl;
            minIdx = minIdxTmp;
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if(distance[i]>=INF){
                return -1;
            }else{
                res = max(res,distance[i]);
            }
        }
        return res;
    }
};