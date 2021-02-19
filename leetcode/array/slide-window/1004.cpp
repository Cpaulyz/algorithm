// https://leetcode-cn.com/problems/max-consecutive-ones-iii/
// Created by admin on 2021/2/19.
// 1. 滑动窗口
// 2. 复用原数组，减少空间复杂度
using namespace std;
#include <vector>

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0,right = 0;
//        vector<int> use(A.size(),0);
//      复用原数组，减少空间复杂度
        int hasUsed = 0;
        int maxLen = 0;
        while (right<A.size()){
            if(A[right]==1){
                right++;
                maxLen = max(maxLen,right-left);
            }else{
//                use[right++]  = 1;
                A[right++] += 2;
                hasUsed+=1;
                while (hasUsed>K){
//                    hasUsed-=use[left++];
                    hasUsed-=A[left++]/2;
                } // make sure hasUsed <= K
                maxLen = max(maxLen,right-left);
            }
        }
        return maxLen;
    }
};

int main(){
    Solution s;
    vector<int> a{1,1,1,0,0,0,1,1,1,1,0};
    s.longestOnes(a,2);
}