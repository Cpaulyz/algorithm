// https://leetcode-cn.com/problems/count-good-meals/
// Created by admin on 2021/7/7.
// 哈希搜索


using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int maxFood = 0;
        int res = 0;
        int mod =  1000000007;
        unordered_map<int,int> cnt_map;
        for(int n:deliciousness){
            maxFood = max(n,maxFood);
        }
        for(int n:deliciousness){
            for (int i = 1; i <= 2*maxFood; i=i<<1) {
                res += cnt_map[i-n];
                res %= mod;
            }
            cnt_map[n]++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v{1,3,5,7,9};
    s.countPairs(v);
}