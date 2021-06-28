// https://leetcode-cn.com/problems/bus-routes/submissions/
// Created by admin on 2021/6/28.
// 双向BFS+两个map优化

using namespace std;

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
        unordered_map<int,unordered_set<int>> station_bus; // 每一站对应的车车
        for (int i = 0; i < routes.size(); ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                if(station_bus.count(routes[i][j])==0){
                    station_bus[routes[i][j]] = unordered_set<int>();
                }
                station_bus[routes[i][j]].insert(i);
            }
        }
        unordered_set<int> gone1 = station_bus[source]; // 查过了的车
        unordered_map<int,int> gone_station1; // 车站：需要的乘车数
        unordered_set<int> gone2 = station_bus[source]; // 查过了的车
        unordered_map<int,int> gone_station2; // 车站：需要的乘车数
        gone_station1[source] = 0;
        gone_station2[target] = 0;
        queue<int> curr_bus1; // 现在要查的车
        queue<int> curr_bus2; // 现在要查的车
        for(auto bus:station_bus[source]){
            curr_bus1.push(bus);
        }
        for(auto bus:station_bus[target]){
            curr_bus2.push(bus);
        }
        int path = 1;
        while (!curr_bus1.empty()&&!curr_bus2.empty()){
            int sz = curr_bus1.size();
            for (int i = 0; i < sz; ++i) {
                // bfs
                int tmp = curr_bus1.front();
                curr_bus1.pop();
                for(int station:routes[tmp]){
                    if(gone_station2.count(station)!=0){
                        return gone_station2[station]+path;
                    }
                    if(gone_station1.count(station)==0){
                        for(int bus:station_bus[station]){
                            if(gone1.count(bus)==0){
                                curr_bus1.push(bus);
                            }
                        }
                        gone_station1[station] = path;
                    }
                }
            }
            sz = curr_bus2.size();
            for (int i = 0; i < sz; ++i) {
                // bfs
                int tmp = curr_bus2.front();
                curr_bus2.pop();
                for(int station:routes[tmp]){
                    if(gone_station1.count(station)!=0){
                        return gone_station1[station]+path;
                    }
                    if(gone_station2.count(station)==0){
                        for(int bus:station_bus[station]){
                            if(gone2.count(bus)==0){
                                curr_bus2.push(bus);
                            }
                        }
                        gone_station2[station] = path;
                    }
                }
            }
            path++;
        }
        return -1;
    }
};