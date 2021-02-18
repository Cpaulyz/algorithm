// https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/
// Created by admin on 2021/2/18.
// 最初思想：贪心，操作原数组，结果超时
// 优化时间复杂度：滑动窗口，记录翻转次数，不真正做翻转，每位翻转会影响到后K位
// 优化空间复杂度：用原数组来记录翻转次数，不另外开数组

using namespace std;
#include <vector>

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int cnt = 0;
        int reverse = 0;
        int left=0,right=0;
//        vector<int> revCnt(A.size(),0);
//      优化：在原数组上+2来代表反转过
        for (right = 0; right < K; ++right) {
            if(A[right]==reverse%2){ // 需要反转的情况 1.原1，反转过奇数次 2.原0，反转过偶数次
                if(right+K>A.size()){
                    return -1;
                }
//                revCnt[right] = 1;
                A[right]+=2;
                reverse++;
                cnt++;
            }
        }
        for (right = K; right < A.size(); ++right) {
//            reverse-=revCnt[left++];
            reverse-=A[left++]/2;
            if(A[right]==reverse%2){ // 需要反转的情况 1.原1，反转过奇数次 2.原0，反转过偶数次
                if(right+K>A.size()){
                    return -1;
                }
//                revCnt[right] = 1;
                A[right]+=2;
                reverse++;
                cnt++;
            }
        }
        return cnt;
    }
};