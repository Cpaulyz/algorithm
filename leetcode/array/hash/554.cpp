// https://leetcode-cn.com/problems/brick-wall/
// Created by admin on 2021/5/4.
// 哈希表，时空O(mn)

using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // <宽,穿梭行数>
        unordered_map<int,int> map;
        // init
        for (int i = 0; i < wall.size(); ++i) {
            int tmp = 0;
            for (int j = 0; j < wall[i].size()-1; ++j) {
                tmp+=wall[i][j];
                map[tmp]+=1;
            }
        }
        // calculate
        int maxNoCross = INT32_MIN;
        for(auto it=map.begin();it!=map.end();it++){
            // cout << it->first<<","<<it->second << endl;
            if(it->second>maxNoCross){
                maxNoCross = it->second;
            }
        }
        if(maxNoCross!=INT32_MIN)
            return wall.size()-maxNoCross;
        else
            return wall.size();
    }
};