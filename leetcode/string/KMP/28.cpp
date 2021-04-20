// https://leetcode-cn.com/problems/implement-strstr/
// Created by admin on 2021/4/20.
// https://leetcode-cn.com/problems/longest-happy-prefix/solution/zui-chang-kuai-le-qian-zhui-by-leetcode-solution/
// https://leetcode-cn.com/problems/implement-strstr/solution/cpython3-fang-fa-1bfbao-li-pi-pei-fang-f-39gp/
// TODO :KMP
using namespace std;
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
// abababc
// ababc
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        vector<vector<int>> dp(haystack.size()+1,vector<int>(needle.size()+1,0));
        for(int i=0;i<haystack.size();++i){
            for(int j=0;j<needle.size();++j){
                if(haystack[i]==needle[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                    if(dp[i+1][j+1]==needle.size()){
                        return i-needle.size()+1;
                    }
                }
            }
        }
        return -1;
    }

    vector<int> getNext(string& s){
        // KMP next数组
        // TODO
        vector<int> next(s.size()+1,0);
        cout << 0 <<",";
        for(int i=2,j=0;i<s.size()+1;++i){
            if(s[i]==s[j]){
                // i,j同时后移
                next[i]=j+1;
                j++;
            }else{
                while (j>0&&s[i]!=s[j]){
                    // j前移，直到s[i]==s[j]或者j==0
                    j=next[j-1];
                }
                if(s[i]!=s[j]){
                    next[i]=0;
                }else{
                    next[i]=j+1;
                    j++;
                }
            }
            cout << next[i] <<",";
        }
        return next;
    }
};

int main(){
    Solution s;
    string str="ababb";
    s.getNext(str);
}