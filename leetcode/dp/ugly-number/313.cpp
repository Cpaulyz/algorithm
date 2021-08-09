// https://leetcode-cn.com/problems/super-ugly-number/
// Created by 陈彦泽 on 2021/8/9.
// dp 维护n个指针 多路归并的思想
using namespace std;
#include <vector>


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>ugly_num{1};
        vector<int>dp(primes.size(),0);
        for (int i = 0; i < n-1; ++i) {
            int next_ugly = INT32_MAX;
            for (int j = 0; j < primes.size(); ++j) {
                next_ugly = min(next_ugly,ugly_num[dp[j]]*primes[j]);
            }
            // move dp
            for (int j = 0; j < primes.size(); ++j) {
                if(ugly_num[dp[j]]*primes[j]==next_ugly){
                    dp[j]++;
                }
            }
            ugly_num.push_back(next_ugly);
        }
        return ugly_num[n-1];
    }
};

int main(){
    Solution s;
    vector<int> v{2,3,5};
    s.nthSuperUglyNumber(12,v);
}

