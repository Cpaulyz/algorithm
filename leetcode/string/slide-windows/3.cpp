// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
// Created by admin on 2021/2/20.
// 滑动窗口
using namespace std;

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> record;
        int left = 0, right = 0;
        int maxLen = 0;
        while (right < s.size()) {
            record[s[right]]++;
            while (record[s[right]]>1){
                record[s[left++]]--;
            }
            right++;
            maxLen = max(maxLen,right-left);
        }
        return maxLen;
    }
};