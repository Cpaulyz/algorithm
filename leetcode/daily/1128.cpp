// https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
// Created by admin on 2021/1/26.
//

using namespace std;
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        unordered_map<string,int> map;
        for (int i = 0; i < dominoes.size(); ++i) {
            int first = dominoes[i][0];
            int second = dominoes[i][1];
            string s;
            if(first<second){
                s= to_string(first)+","+to_string(second);
            }else{
                s= to_string(second)+","+to_string(first);
            }
            map[s]+=1;
        }
        unordered_map<string,int>::iterator it = map.begin();
        while (it!=map.end()){
            res += it->second * (it->second-1) / 2;
            it++;
        }
        return res;
    }
};