// https://leetcode-cn.com/problems/interval-list-intersections/
// Created by admin on 2020/12/11.
// https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/qu-jian-wen-ti-he-ji

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B) {
        int aleft, aright;
        int bleft, bright;
        vector<vector<int>> res;
        vector<vector<int>>::iterator a = A.begin();
        vector<vector<int>>::iterator b = B.begin();
        while (a != A.end() && b != B.end()) {
            aleft = (*a)[0];
            aright = (*a)[1];
            bleft = (*b)[0];
            bright = (*b)[1];
            int l = max(aleft, bleft);
            int r = min(aright, bright);
            if (l <= r) {
                res.push_back(vector<int>{l, r});
            }
            if (aright >= bright) { // 已经排好序了，谁先结束谁往后
                b++;
            } else {
                a++;
            }
        }
        return res;
    }
};


int main() {
    vector<vector<int>> a;
    a.push_back(vector<int>{0, 2});
    a.push_back(vector<int>{5, 10});
    a.push_back(vector<int>{13, 23});
    a.push_back(vector<int>{24, 25});

    vector<vector<int>> b;
    b.push_back(vector<int>{1, 5});
    b.push_back(vector<int>{8, 12});
    b.push_back(vector<int>{15, 24});
    b.push_back(vector<int>{25, 26});
    Solution s;
    s.intervalIntersection(a, b);

}