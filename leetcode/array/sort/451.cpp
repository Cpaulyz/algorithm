// https://leetcode-cn.com/problems/sort-characters-by-frequency/
// Created by admin on 2021/7/3.
// 排序


using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

struct cnt{
    char c;
    int count;
    cnt(char ch):c(ch),count(0){}
};
bool cmp(cnt* a,cnt *b);
class Solution {
public:

    string frequencySort(string s) {
        unordered_map<char,cnt*> char_map;
        vector<cnt*> set;
        for (int i = 0; i < s.size(); ++i) {
            if(char_map.count(s[i])==0){
                cnt* tmp = new cnt(s[i]);
                set.push_back(tmp);
                char_map[s[i]]=tmp;
            }
            char_map[s[i]]->count++;
        }
        sort(set.begin(),set.end(),cmp);
        string res = "";
        for(auto count:set){
            for (int i = 0; i < count->count; ++i) {
                res += count->c;
            }
        }
        return res;
    }
};

bool cmp(cnt* a,cnt *b){
    return a->count>b->count;
}