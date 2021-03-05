// https://leetcode-cn.com/problems/russian-doll-envelopes/
// Created by admin on 2021/3/4.
// 自己实现了O(n2)的算法
// 标答为O(nlogn)，十分巧妙，写的时候想到了另外一道题(300)，但没想到可以那样改
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> dp(envelopes.size());
        int res = 0;
        for (int i = 0; i < envelopes.size(); ++i) {
            int maxCnt = 0;
            for (int j = 0; j < i; ++j) {
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1])
                    maxCnt = max(maxCnt,dp[j]);
            }
            dp[i] = maxCnt + 1;
            res = max(res,maxCnt+1);
        }
        return res;
    }

    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }else{
            return a[0]<b[0];
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> v;
    v.push_back({5,4});
    v.push_back({6,4});
    v.push_back({6,7});
    v.push_back({20,3});
    s.maxEnvelopes(v);
}