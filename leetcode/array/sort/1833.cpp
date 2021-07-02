// https://leetcode-cn.com/problems/maximum-ice-cream-bars/
// Created by admin on 2021/7/2.
// 排个序就完事了。。。

using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i=0;
        for (i = 0; i < costs.size()&&coins>0; ++i) {
            coins -= costs[i];
            // cout << i << " : " << costs[i] << " " << coins <<endl;
        }
        if(coins<0){
            i--;
        }
        return i;
    }
};