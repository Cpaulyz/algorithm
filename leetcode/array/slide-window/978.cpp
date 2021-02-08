// https://leetcode-cn.com/problems/longest-turbulent-subarray/
// Created by admin on 2021/2/8.
// 右边扩大时需要判断是否符合，左边缩小后一定符合

using namespace std;
#include <vector>

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int left = 0,right = 1;\
        int maxLen = 1;
        while (right<arr.size()){
            if(right-left==1){ // 如果窗口内只有一个元素，只需要判断下一个不等即可
                if (arr[right]!=arr[right-1]){
                    right++;
                    maxLen = max(maxLen,right-left); // 一定符合
                }else{
                    left++;
                    right++;
                }
            }else{
                if((arr[right]>arr[right-1]&&arr[right-2]>arr[right-1])||(arr[right]<arr[right-1]&&arr[right-2]<arr[right-1])){
                    right++;
                    maxLen = max(maxLen,right-left);
                }else{
                    left++;
                }
            }
        }
        return maxLen;
    }
};