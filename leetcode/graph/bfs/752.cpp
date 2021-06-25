// https://leetcode-cn.com/problems/open-the-lock/
// Created by admin on 2021/6/25.
// 双向BFS

using namespace std;

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <iostream>
class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> dead = unordered_set<string>(deadends.begin(), deadends.end());
        if (target=="0000"){
            return 0;
        }else if(dead.count("0000")!=0){
            return -1;
        }
        unordered_map<string, int> pos_map; // 正向搜索记录，{"1000":1} 代表 "1000" 由 s="0000" 替换 1 次字符而来
        unordered_map<string, int> reverse_map; // 反向搜索记录
        pos_map["0000"] = 0;
        reverse_map[target] = 0;
        queue <string> pos = queue<string>({"0000"});
        queue <string> rev = queue<string>({target});
        bool loop = true;
        int path = 0;
        while (loop) {
            path++;
            int sz_pos = pos.size();
            int sz_rev = rev.size();
            if (sz_pos + sz_rev == 0) {
                break;
            }
            for (int i = 0; i < sz_pos; ++i) {
                cout << "pos" << endl;
                string tmp = pos.front();
                pos.pop();
                int res = move(dead,pos , pos_map, reverse_map, tmp, path);
                if (res > 0) {
                    return res;
                }
                cout <<"====================="<<endl;
            }
            for (int i = 0; i < sz_rev; ++i) {
                cout << "rev" << endl;
                string tmp = rev.front();
                rev.pop();
                int res = move(dead, rev, reverse_map, pos_map, tmp, path);
                if (res > 0) {
                    return res;
                }
                cout <<"====================="<<endl;
            }
        }
        return -1;
    }

    int move(unordered_set<string> &dead, queue<string> &que, unordered_map<string, int> &curr_map,
             unordered_map<string, int> &other_map, string now, int path) {
        for (int i = 0; i < 4; ++i) {
            string tmp = now;
            tmp[i] = tmp[i] == '0' ? '9' : tmp[i] - 1;
            if (dead.count(tmp) == 0) {
                cout << path << ":" << tmp<<endl;
                if (other_map.count(tmp) != 0) {
                    cout << "meet!"<<endl;
                    return path + other_map[tmp];
                } else if (curr_map.count(tmp) == 0) {
                    que.push(tmp);
                    curr_map[tmp] = path;
                }
            }
            tmp = now;
            tmp[i] = tmp[i] == '9' ? '0' : tmp[i] + 1;
            if (dead.count(tmp) == 0) {
                cout << path << ":" << tmp<<endl;
                if (other_map.count(tmp) != 0) {
                    cout << "meet!"<<endl;
                    return path + other_map[tmp];
                } else if (curr_map.count(tmp) == 0) {
                    que.push(tmp);
                    curr_map[tmp] = path;
                }
            }
        }
        return 0;
    }
};