// https://leetcode-cn.com/problems/group-anagrams-lcci/
// Created by admin on 2021/7/18.
// 计数排序
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> record;
        for (int i = 0; i < strs.size(); ++i) {
            string tmp = serialize(strs[i]);
            if(record.count(tmp)==0){
                record[tmp] = vector<string>();
            }
            record[tmp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto item:record){
            res.push_back(item.second);
        }
        return res;
    }

    string serialize(string& str){
        vector<int> cnt(26,0);
        for (char c:str){
            cnt[c-'a']++;
        }
        string res = "";
        for (int i = 0; i < 26; ++i) {
            if(cnt[i]!=0){
                res += string ('a'+i,1);
                res += to_string(cnt[i]);
            }
        }
        return res;
    }
};