// https://leetcode-cn.com/problems/number-of-boomerangs/
// Created by 陈彦泽 on 2021/9/13.
// 暴力枚举+哈希表


using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if(points.size()<3){
            return 0;
        }
        int n = points.size();
        vector<vector<int>> instances(n,vector<int>(n,0)); // 距离矩阵
        int res = 0;
        unordered_map<int,int> map;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                instances[i][j] = instances[j][i];
                map[instances[i][j]]++;
            }
            for(int j=i+1;j<n;++j){
                instances[i][j] = getInstance(points[i],points[j]);
                map[instances[i][j]]++;
            }
            for(auto item:map){
                if(item.second>1){
                    res += (item.second)*(item.second-1);
                }
            }
            map.clear();
        }
        return res;
    }

    int getInstance(vector<int>& a,vector<int>& b){
        // 直接返回平方吧
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
};