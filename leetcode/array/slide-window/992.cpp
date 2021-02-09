// https://leetcode-cn.com/problems/subarrays-with-k-different-integers/
// Created by admin on 2021/2/9.
// 不同于简单滑动窗口的的在于，可能出现 [ 1 1 2 2 3 3 ] , K=2的情况
// 这个解法似乎运行最优
using namespace std;
#include <vector>
#include <unordered_map>
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
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
            // diff==K
            int tmpLeft = left;
            while (diff==K){ // 计数
                cnt++;
                int l = A[tmpLeft++];
                record[l]--;
                if(record[l]==0){
                    diff--;
                }
            }
            for (int i = left; i < tmpLeft; ++i) { // 还原
                int l = A[i];
                record[l]++;
                if(record[l]==1){
                    diff++;
                }
            }
            // diff<K do nothing
            right++;
        }
        return cnt;
    }
};