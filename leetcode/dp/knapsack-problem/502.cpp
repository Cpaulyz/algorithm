// https://leetcode-cn.com/problems/ipo/
// Created by 陈彦泽 on 2021/9/8.
// 该解法有一部分用例超时

// dp[i][j]
// 按capital排序，从小到大贪心选，排除负收益的
// 从前i个项目里挑j个，挑完以后的最大资产
// 1. 要i：dp[i-1][j-1]>=capital[i], dp[i][j]=dp[i-1][j-1]+profits[i]
// 2. 不要i：dp[i][j] = dp[i-1][j]


using namespace std;

#include <vector>
#include <algorithm>

struct project {
    int profit;
    int capital;

    project(int profit, int capital) : profit(profit), capital(capital) {};
};

bool cmp(project *a, project *b);

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int res = w;
        vector < project * > projects;
        int sz = profits.size();
        for (int i = 0; i < sz; ++i) {
            projects.push_back(new project(profits[i], capital[i]));
        }
        sort(projects.begin(), projects.end(), cmp);
        if(projects[sz-1]->capital<=w){
            // 直接挑最大收益的n个
            sort(profits.begin(),profits.end());
            for (int i = 0; i < k; ++i) {
                res += profits[sz-1-i];
            }
            return res;
        }
        vector <vector<int>> dp(sz, vector<int>(k + 1, 0));
        // init
        dp[0][0] = w;
        if (projects[0]->capital <= w) {
            dp[0][1] = w + projects[0]->profit;
        }
        for (int i = 1; i < sz; ++i) {
            dp[i][0] = w;
            for (int j = 1; j <= k; ++j) {
                if (dp[i - 1][j - 1] >= projects[i]->capital) {
                    dp[i][j] = dp[i - 1][j - 1] + projects[i]->profit;
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                res = max(res, dp[i][j]);

            }
        }
        return res;
    }
};


bool cmp(project *a, project *b) {
    return a->capital < b->capital;
}

int main() {
    vector<int> c{0, 1, 1};
    vector<int> p{1, 2, 3};
    Solution s;
    s.findMaximizedCapital(2, 0, p, c);

}