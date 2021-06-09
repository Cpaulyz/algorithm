// https://blog.csdn.net/da_kao_la/article/details/82425671
// Created by admin on 2021/6/8.
/* 从控制台输入n+1 行，前n 行每行3 个整数，形如“A B d”，表示从节点A 到节点B 距离为d（双向）。第n+1 行形如“A B”，表示求A 到B 的最短距离。输出此最短距离。
例如：
1 42 3
42 789 4
1 789 9
1 789
输出
7
*/
using namespace std;

#include <vector>
#include <iostream>
#include <unordered_map>

#define INF 99999

class Solution {
public:
    int shortPath(vector<vector<int>> &path, int src, int tar) {
        vector<int> res(path.size(), INF);
        vector<bool> visited(path.size(), false);
        visited[src] = true;
        for (int i = 0; i < path.size(); ++i) {
            res[i] = path[src][i];
//            cout << res[i] <<  " ";
        }
//        cout << endl;
        for (int i = 1; i < path.size(); ++i) {
            int tmp = 0;
            int mini = INF;
            for (int j = 0; j < res.size(); ++j) {
                if ((!visited[i]) && res[i] < mini) {
                    mini = res[i];
                    tmp = i;
                }
            }
            for (int j = 0; j < res.size(); ++j) {
                if (res[j] > res[tmp] + path[j][tmp]) {
                    res[j] = res[tmp] + path[j][tmp];
                }

//                cout << res[j] <<  " ";
            }
//            cout << endl;
            visited[tmp] = true;
        }
        return res[tar];
    }
};

int main() {
    int src, tar, tmp;
    int index = 0;
    unordered_map<int, int> map;
    vector <vector<int>> record;
    while (cin >> src >> tar) {
        cin >> tmp;
        if (map.count(src) == 0) {
            map[src] = index++;
        }
        if (map.count(tar) == 0) {
            map[tar] = index++;
        }
        record.push_back({src, tar, tmp});
    }
    record.pop_back();
    Solution s;
    vector <vector<int>> path(map.size(), vector<int>(map.size(), INF));
    for (int i = 0; i < record.size(); ++i) {
        int map_src = map[record[i][0]];
        int map_tar = map[record[i][1]];
        path[map_src][map_tar] = path[map_tar][map_src] = record[i][2];
//        cout << map_src << "-->" << map_tar << ":" << record[i][2] << endl;
    }
    int res = s.shortPath(path, map[src], map[tar]);
    cout << res;
}

