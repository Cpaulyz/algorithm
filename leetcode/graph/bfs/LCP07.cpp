// https://leetcode-cn.com/problems/chuan-di-xin-xi/
// Created by admin on 2021/7/1.
//
using namespace std;

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int numWays(int n, vector<vector<int>> &relation, int k) {
        unordered_map<int, vector<int>> rels;
        queue<int> curr;
        curr.push(0);
        for (auto rel:relation) {
            if (rels.count(rel[0]) == 0) {
                rels[rel[0]] = vector<int>();
            }
            rels[rel[0]].push_back(rel[1]);
        }
        for (int i = 0; i < k; ++i) {
            // cout << i << endl;
            int sz = curr.size();
            for (int j = 0; j < sz; ++j) {
                int tmp = curr.front();
                curr.pop();
                for (int to:rels[tmp]) {
                    // cout << to << " ";
                    curr.push(to);
                }
            }
            // cout  << endl << "============" << endl;
        }
        int res = 0;
        while (!curr.empty()){
            res += curr.front()==n-1?1:0;
            curr.pop();
        }
        return res;
    }
};