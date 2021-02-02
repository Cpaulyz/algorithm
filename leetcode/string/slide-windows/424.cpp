// https://leetcode-cn.com/problems/longest-repeating-character-replacement/
// Created by admin on 2021/2/2.
// 滑动窗口，双指针

using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    // 改进前的，窗口会增大缩小，时间复杂度高
    int characterReplacement(string s, int k) {
        vector<int> chars(26,0);
        int maxLen = 0;
        int left = 0 ,right = 0; // 左右指针
        while (right!=s.size()){
            chars[s.at(right++)-'A']++;
            while (check(chars,k)== false){
                chars[s.at(left++)-'A']--;
            }
            maxLen = max(maxLen,right-left);
        }
        return maxLen;
    }

    // 改进后的，窗口只会增大不会减小，可以减少时间复杂度
//    int characterReplacement(string s, int k) {
//        vector<int> chars(26,0);
//        int maxLen = 0;
//        int left = 0 ,right = 0; // 左右指针
//        while (right<s.size()){
//            if (check(chars,k)== false){
//                // 窗口滑动
//                chars[s.at(left++)-'A']--;
//                chars[s.at(right++)-'A']++;
//            }else{
//                // 窗口扩张
//                chars[s.at(right++)-'A']++;
//                maxLen = max(maxLen,right-left);
//            }
//        }
//        // 最后判断
//        if (check(chars,k)){
//            maxLen = max(maxLen,right-left);
//        }
//        return maxLen;
//    }

    bool check(vector<int>& chars,int k){
        int max = 0,maxIndex = 0;
        for (int i = 0; i < chars.size(); ++i) {
            if(chars[i]>max){
                max = chars[i];
                maxIndex = i;
            }
        }
        int otherSum = 0 ;
        for (int i = 0; i < chars.size(); ++i) {
            if(i!=maxIndex){
                otherSum+=chars[i];
            }
        }
        return otherSum<=k;
    }
};

int main(){
    Solution s;
    s.characterReplacement("AABABBA",1);
}