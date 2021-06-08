// https://blog.csdn.net/zhongershuchong/article/details/108622480
// Created by admin on 2021/6/7.
// 给N < M < 1e5, 从p出发走一步可以到p+k( k是p 因数且k != 1 且 k != p），求N到M最小步数
// 5 6 7 8 9
using namespace std;

#include <vector>
#include <math.h>
#include <iostream>

class Solution{
public:
    int minPath(int N,int M){
        vector<int> dp(M-N+1,99999);
        dp[0] = 0;
        for(int i=N;i<=M;++i){
            for (int j = 2; j <= sqrt(i); ++j) {
                if(i%j==0){
                    dp[i-N+j-1] = min(dp[i-N+j-1],dp[i-N]+1);
                }
            }
        }
        return dp[M-N];
    }
};

int main(){
    Solution s;
}