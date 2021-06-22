// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
// Created by admin on 2021/6/22.
// 全排列、回溯

class Solution {
    vector<string> res;
public:
    vector<string> permutation(string s) {
        res = vector<string>();
        vector<char> char_list;
        unordered_map<char,int> char_num;
        for(int i=0;i<s.size();++i){
            char tmp = s[i];
            if(char_num[tmp]==0){
                char_list.push_back(tmp);
            }
            char_num[tmp]++;
        }
        dfs(char_list,char_num,"",s.size());
        return res;
    }

    void dfs(vector<char>& char_list, unordered_map<char,int>& char_num,string s,int len){
        if(s.size()==len){
            res.push_back(s);
        }
        for(char c:char_list){
            if(char_num[c]!=0){
                char_num[c]--;
                dfs(char_list,char_num,s+c,len);
                char_num[c]++;
            }
        }
    }
};