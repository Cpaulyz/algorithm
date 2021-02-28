// https://leetcode-cn.com/problems/super-egg-drop/
// Created by admin on 2021/2/28.
//
using namespace std;

#include <vector>
#include <unordered_map>

class Solution {
public:
    unordered_map<int,int> map;

    int superEggDrop(int K, int N) {
        return dp(K, N);
    }

    int dp(int K, int N) {
        if (K == 1) {
            return N;
        }
        if (N == 0) {
            return 0;
        }
        int key = N*100+K;
        if(map[key]!=0){
            return map[key];
        }
        int minDrop = N;
        for (int i = 0; i < N; ++i) {
            minDrop = min(
                    max(
                            dp(K - 1, i - 1), // 碎了
                            dp(K, N - i)  // 没碎
                    ) + 1,
                    minDrop);
        }
        map[key] = minDrop;
        return minDrop;
    }
};