// https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/
// Created by 陈彦泽 on 2021/9/11.
// 数位dp的模板题
using namespace std;
#include <vector>


class Solution {
public:
    int findIntegers(int n) {
        // dp[i] 表示i位二进制数中（不含前导0），满足的个数
        // dp[i] = dp[i-2]+dp[i-3]+...+dp[0] = dp[i-1]+dp[i-2]
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(1);
        dp.push_back(1);
        int len = 0; // n中，最高位1的位数（从1开始算）
        while((1<<len)<=n){
            len++;
        }
        for(int i =3;i<len;++i){
            dp.push_back(dp[i-1]+dp[i-2]);
        }
        int res = 0;
        bool getOne = false;
        bool match = true; // n是否符合
        for (int i = len-1; i >=0; --i) { // 计算比n小的数，有几个符合
            if(((1<<i)&n)!=0){
                for (int j = 0; j <= i; ++j) {
                    res += dp[j];
                }
                if(getOne){
                    match = false;
                    break;
                }
                getOne = true;
            }else{
                getOne = false;
            }
        }
        res += match?1:0;
        // 100 101 110 111
        // 1010 1000 1001
        // 1000
        return res;
    }
};

int main(){
    Solution s;
    s.findIntegers(8);
}