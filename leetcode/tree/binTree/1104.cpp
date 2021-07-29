// https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/
// Created by admin on 2021/7/29.
// 数学题。。。

using namespace std;

#include <vector>
#include <unordered_map>
#include <stack>

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int i = 1;
        stack<int> level_start;
        while (i<=label){
            level_start.push(i);
            i*=2;
        }
        vector<int> res;
        while (label!=1){
            res.push_back(label);
            label = label/2;
            int tmp = level_start.top();
            level_start.pop();
            label = level_start.top()-1+(tmp-label);
        }
        res.push_back(1);
        return vector<int>(res.rbegin(),res.rend());
    }
};

int main(){
    Solution s;
    s.pathInZigZagTree(14);
}