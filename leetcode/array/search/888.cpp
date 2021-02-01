// https://leetcode-cn.com/problems/fair-candy-swap/
// Created by admin on 2021/2/1.
// 很简单一道求和的题目，用到了哈希来优化查找速度

using namespace std;

#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
        int suma = 0, sumb = 0;
        for (int i = 0; i < A.size(); ++i) {
            suma += A[i];
        }
        for (int i = 0; i < B.size(); ++i) {
            sumb += B[i];
        }
        unordered_set<int> setB(B.begin(), B.end());
        vector<int> res;
        int diff = suma - sumb;
        for (int a:A) {
            int b = a - diff / 2;
            if (setB.count(b)) {
                res.push_back(a);
                res.push_back(b);
                return res;
            }
        }
        return res;
    }
};