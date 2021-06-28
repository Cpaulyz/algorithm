//https://leetcode-cn.com/problems/bus-routes/
// Created by admin on 2021/3/7.
// BFS

using namespace std;

#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        unordered_map<int, int> use; // 是否查过车
        unordered_map<int, set<int>> dic; // 站点:[公交线路..]
        for (int i = 0; i < routes.size(); ++i) {
            for (int r:routes[i]) {
                dic[r].insert(i);
            }
        }
        // bfs
        int cnt = 0;
        queue<int> tmp; // 待检查的站点
        // init
        tmp.push(source);
//        for (int n:dic[source]) {
//            tmp.push(n);
//        }
        while (!tmp.empty()) {
            int size = tmp.size();
            for (int i = 0; i < size; ++i) {
                int station = tmp.front();
                tmp.pop();
                use[station] = 1;
                if (station == target) {
                    return cnt;
                }
                for (int bus:dic[station]) {
                    if(use[bus]!=0){
                        continue;
                    }
                    use[bus] = 1;
                    for (int& stop:routes[bus]){
                        tmp.push(stop);
                    }
                }

            }
            cnt++;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector <vector<int>> routes;
    routes.push_back({0, 1, 6, 16, 22, 23});
    routes.push_back({14, 15, 24, 32});
    routes.push_back({4, 10, 12, 20, 24, 28, 33});
    routes.push_back({1, 10, 11, 19, 27, 33});
    routes.push_back({11, 23, 25, 28});
    routes.push_back({15, 20, 21, 23, 29});
    routes.push_back({29});
    s.numBusesToDestination(routes, 4, 21);
}
