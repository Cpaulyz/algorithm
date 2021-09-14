// https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/
// Created by 陈彦泽 on 2021/9/14.
// 排序+双指针
using namespace std;
#include <vector>
#include <string>

bool cmp(string& a,string& b);

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // 排个序
        sort(dictionary.begin(),dictionary.end(), cmp);
        for(string d:dictionary){
            if(contain(s,d)){
                return d;
            }
        }
        return "";
    }
    bool contain(string& s,string& sub){
        if(sub.size()>s.size()){
            return false;
        }
        int index=0;
        for (int i = 0; i < sub.size(); ++i) {
            while(index<s.size()&&s[index++]!=sub[i]);
            if(sub[i]!=s[index-1]){
                return false;
            }
        }
        return true;
    }
};
bool cmp(string& a,string& b){
    if(a.size()!=b.size()){
        return a.size()>b.size();
    }else{
        for (int i = 0; i < a.size(); ++i) {
            if(a[i]!=b[i]){
                return a[i]<b[i];
            }
        }
        return false;
    }
}