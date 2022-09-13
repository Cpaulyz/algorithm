// https://leetcode.cn/problems/maximum-swap/
// Created by 陈彦泽 on 2022/9/13.
// 贪心
using namespace std;
#include <vector>

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> n(9,0) ;
        int maxPos = 0;
        int startPos = 0;
        int index1 = -1, index2 = -1;
        for (int i = 0; i < 9; ++i) {
            n[8-i] = num%10;
            num = num/10;
            if(n[8-i]>n[maxPos]){
                maxPos = 8-i;
            }else if(n[8-i]<n[maxPos]){
                index1 = 8-i;
                index2 = maxPos;
            }
            if(num==0){
                startPos = 8-i;
                break;
            }
        }
        if(index1>0){
            int tmp = n[index1];
            n[index1] = n[index2];
            n[index2] = tmp;
        }
        int res = 0;
        for (int i = startPos; i < 9; ++i) {
            res *= 10;
            res+=n[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    s.maximumSwap(98368);
}