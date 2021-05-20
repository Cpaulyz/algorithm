// https://leetcode-cn.com/problems/top-k-frequent-words/
// Created by admin on 2021/5/20.
// 哈希表+优先队列(自定义比较函数)
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

struct Pair{
    int cnt;
    string str;
    Pair(int c,string s):cnt(c),str(s){};
};

struct cmp{
    bool operator ()(const Pair* a, const Pair* b)
    {
        if(a->cnt==b->cnt){
            return a->str.compare(b->str)<0;
        }else{
            return a->cnt>b->cnt;
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> cnt;
        priority_queue<Pair*,vector<Pair*>,cmp> queue;
        vector<string> res(k);
        for(string s:words){
            cnt[s]++;
        }
        for(auto it=cnt.begin();it!=cnt.end();it++){
            queue.push(new Pair(it->second,it->first));
            while(queue.size()>k){
                queue.pop();
            }
        }
        for (int i = k-1; i >=0; --i) {
            Pair* tmp = queue.top();
            res[i]=tmp->str;
            queue.pop();
        }
        return res;
    }
};