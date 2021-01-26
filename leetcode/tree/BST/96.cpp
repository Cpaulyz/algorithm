// https://leetcode-cn.com/problems/unique-binary-search-trees/
// Created by admin on 2021/1/26.
// 本质上是dp

using namespace std;
#include <vector>

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(1);
        for (int i = 2 ; i <= n; ++i) {
            int tmp = 0;
            for (int j = 1; j <= i; ++j) {
                tmp+=dp[j-1]*dp[i-j];
            }
            dp.push_back(tmp);
        }
        return dp[n];
    }
};
int main(){
    Solution s;
    s.numTrees(3);
}