// https://leetcode-cn.com/problems/maximum-element-after-decreasing-and-rearranging/
// Created by admin on 2021/7/15.
// 排序+贪心


using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // 直接模拟算了
        sort(arr.begin(),arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); ++i) {
            if(arr[i]-arr[i-1]>1){
                arr[i] = arr[i-1]+1;
            }
        }
        return arr[arr.size()-1];
    }
};