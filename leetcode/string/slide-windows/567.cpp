// https://leetcode-cn.com/problems/permutation-in-string/
// Created by admin on 2021/2/10.
// 滑动窗口，vector维护字符次数
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        vector<int> c1(26),c2(26);
        for (int i = 0; i < s1.size(); ++i) {
            c1[s1[i]-'a']++;
            c2[s2[i]-'a']++;
        } // init
        if(check(c1,c2)){
            return true;
        }
        int left = 0,right = s1.size();
        while (right<s2.size()){
            c2[s2[left++]-'a']--;
            c2[s2[right++]-'a']++;
            if(check(c1,c2)){
                return true;
            }
        }
        return false;

    }
    bool check(vector<int>&c1,vector<int>&c2){
        for (int i = 0; i < c1.size(); ++i) {
            if(c1[i]!=c2[i]){
                return false;
            }
        }
        return true;
    }
};