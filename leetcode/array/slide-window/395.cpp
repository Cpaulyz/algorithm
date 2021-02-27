// https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/
// Created by admin on 2021/2/27.
// 滑动窗口
using namespace std;
#include <vector>
#include <string>
class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> record(26);
        vector<int> wnd(26);
        int kind = 0;
        int maxLen = 0;
        for(char c:s){
            if(record[c-'a']==0){
                kind++;
            }
            record[c-'a']++;
        }
        for (int p = 1; p <= kind; ++p) {
            for (int i = 0; i < wnd.size(); ++i) {
                wnd[i] = 0;
            }
            int left = 0,right =0;
            int less = 0;
            int numChar = 0;
            while (right<s.size()){
                wnd[s[right]-'a']++;
                if(wnd[s[right]-'a']==1){
                    numChar++;
                    if(k>1){
                        less++;
                    }
                }else if(wnd[s[right]-'a']==k){
                    less--;
                }
                while (numChar>p){
                    wnd[s[left]-'a']--;
                    if(wnd[s[left]-'a']==0){
                        numChar--;
                        less--;
                    }else if(wnd[s[left]-'a']==k-1){
                        less++;
                    }
                    left++;
                }
                if(less==0){
                    maxLen = max(maxLen,right-left+1);
                }
                right++;
            }
        }
        return maxLen;
    }
};

int main(){
    Solution s;
    s.longestSubstring("ababbc",2);
}