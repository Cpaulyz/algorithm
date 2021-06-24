// https://leetcode-cn.com/problems/max-points-on-a-line/submissions/
// Created by admin on 2021/6/24.
// O(n2)遍历直线
// 因为斜率精度不好表示，拿序列化的string来表示
// 因为点不好表示，直接拿string来表示
// gcd函数不好写
// 情况1： 如果不是垂直于x轴，key为斜率+截距
// 情况2： 如果垂直x轴，斜率直接为x


using namespace  std;
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <iostream>

class Solution {
    unordered_map<string ,unordered_set<string>> lines;
    int res;
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1){
            return 1;
        }
        lines = unordered_map<string,unordered_set<string>>();
        res = 0;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i+1; j < points.size(); ++j) {
                add(points[i][0],points[i][1],points[j][0],points[j][1]);
            }
        }
        return res;
    }

    void add(int x1,int y1,int x2,int y2){
        // y1 = ax1 + b
        // y2 = ax2 + b
        // a = (y2-y1)/(x2-x1)
        // b = y1 - ax1 = (x2y1-x1y2)/(x2-x1)
        int diffx = x2-x1;
        string key = "";
        if (diffx!=0){
            int diffy = y2-y1;
            int g = gcd(diffx,diffy);
            key = to_string(diffy/g)+","+to_string(diffx/g);
            diffy = x2*y1-x1*y2;
            g = gcd(diffx,diffy);
            key = key+","+to_string(diffy/g)+","+to_string(diffx/g);
        }else{
            key = to_string(x1);
        }
        string p1 = to_string(x1)+","+to_string(y1);
        string p2 = to_string(x2)+","+to_string(y2);
        lines[key].insert(p1);
        lines[key].insert(p2);
        if (lines[key].size()>res){
            res = lines[key].size();
        }
    }

    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
};