// https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
// Created by admin on 2021/2/5.
// 滑动窗口+字符串
using namespace std;

#include <string>

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0;
        int maxLen = 0;
        int cost = 0;
        while (right != s.size()) {
            if (cost<=maxCost) {
                maxLen = max(maxLen, right - left);
                cost+= abs(s[right] - t[right]);
                right++;
            } else {
                cost+= abs(s[right] - t[right]);
                cost-= abs(s[left] - t[left]);
                left++;
                right++;
            }
        }
        if (cost<=maxCost) {
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }
};