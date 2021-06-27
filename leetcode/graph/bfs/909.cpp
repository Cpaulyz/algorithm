// https://leetcode-cn.com/problems/snakes-and-ladders/
// Created by admin on 2021/6/27.
// BFS

using namespace std;

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>

class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        unordered_set<int> gone; // 走过的
        gone.insert(1);
        queue<int> curr = queue<int>({1});
        int target = board.size() * board[0].size();
        int path = 1;
        while (!curr.empty()) {
            int sz = curr.size();
            for (int i = 0; i < sz; ++i) {
                int now = curr.front();
                curr.pop();
                for (int i = 1; i <= 6; ++i) {
                    if (now + i <= target) {
                        if (add(now + i, board, gone, curr, target)) {
                            return path;
                        }
                    }
                }
            }
            path++;
        }
        return -1;
    }

    /**
     * 这边需要注意，如果传送了，那么不需要判断原位置有没有gone过，相当于直接到传送点
     */
    bool add(int now, vector<vector<int>> &board, unordered_set<int> &gone, queue<int> &curr, int target) {
        int jump = getNum(board, now);
        if (jump != -1) {
            if (gone.count(jump) == 0) {
                gone.insert(jump);
                curr.push(jump);
                if (jump == target) {
                    return true;
                }
            }
        } else {
            if (gone.count(now) == 0) {
                gone.insert(now);
                curr.push(now);
                if (now == target) {
                    return true;
                }
            }
        }
        return false;
    }

    int getNum(vector<vector<int>> &board, int index) {
        int line_size = board.size();
        int row_size = board[0].size();
        int line = (index - 1) / row_size;
        if (line % 2 == 0) {
            return board[line_size - line - 1][(index - 1) % row_size];
        } else {
            return board[line_size - line - 1][row_size - 1 - (index - 1) % row_size];
        }
    }
};

int main() {
    Solution s;
    vector <vector<int>> v = vector < vector < int >> ();
    v.push_back({-1, -1, -1, 46, 47, -1, -1, -1});
    v.push_back({51, -1, -1, 63, -1, 31, 21, -1});
    v.push_back({-1, -1, 26, -1, -1, 38, -1, -1});
    v.push_back({-1, -1, 11, -1, 14, 23, 56, 57});
    v.push_back({11, -1, -1, -1, 49, 36, -1, 48});
    v.push_back({-1, -1, -1, 33, 56, -1, 57, 21});
    v.push_back({-1, -1, -1, -1, -1, -1, 2, -1});
    v.push_back({-1, -1, -1, 8, 3, -1, 6, 56});
    cout << s.snakesAndLadders(v);
}

/*
[[-1,-1,-1,46,47,-1,-1,-1],
 [51,-1,-1,63,-1,31,21,-1],
 [-1,-1,26,-1,-1,38,-1,-1],
 [-1,-1,11,-1,14,23,56,57],
 [11,-1,-1,-1,49,36,-1,48],
 [-1,-1,-1,33,56,-1,57,21],
 [-1,-1,-1,-1,-1,-1,2,-1],
 [-1,-1,-1,8,3,-1,6,56]]
*/