// https://leetcode-cn.com/problems/ipo/
// Created by 陈彦泽 on 2021/9/8.
// 优先队列解法


using namespace std;

#include <vector>
#include <algorithm>
#include <queue>

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
        int index = 0;
        priority_queue<int,vector<int>,less<int>> heap;
        for (int i = 0; i < k; ++i) {
            while (index<sz && projects[index]->capital<=res){
                heap.push(projects[index]->profit);
                index++;
            }
            if(heap.empty()){
                break;
            }
            res += heap.top();
            heap.pop();
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