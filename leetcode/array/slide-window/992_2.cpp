// https://leetcode-cn.com/problems/subarrays-with-k-different-integers/
// Created by admin on 2021/2/9.
// 不同于简单滑动窗口的的在于，可能出现 [ 1 1 2 2 3 3 ] , K=2的情况
// 恰好k个=最多k个-最多(k-1)个，这个思想很值得学习
// https://leetcode-cn.com/problems/subarrays-with-k-different-integers/solution/cong-zui-jian-dan-de-wen-ti-yi-bu-bu-tuo-7f4v/
using namespace std;
#include <vector>
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return helper(A,K)-helper(A,K-1);
    }

    int helper(vector<int>&A,int K){
        vector<int>record(A.size()+1,0);
        int cnt = 0;
        int diff = 0;
        int left = 0;
        int right = 0;
        while (right<A.size()){
            // 向右扩张
            int r = A[right];
            record[r]++;
            if(record[r]==1){
                diff++;
            }
            // diff>K 尝试收缩左侧
            while (diff>K){
                int l = A[left++];
                record[l]--;
                if(record[l]==0){
                    diff--;
                }
            }
            if(diff==K){
                cnt += right-left;
            }
            // diff<K do nothing
            right++;
        }
        return cnt;
    }

};