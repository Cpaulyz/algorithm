// https://leetcode-cn.com/problems/merge-intervals/
// Created by admin on 2020/12/11.
// https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/qu-jian-wen-ti-he-ji

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(vector<int>&a,vector<int>&b);
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int left,right;
        vector<vector<int>> res;
        left = intervals[0][0];
        right = intervals[0][1];
        for (vector<vector<int>>::iterator it = intervals.begin()+1; it != intervals.end(); it++){
            if((*it)[1]<=right){ // 包含关系
                continue;
            }else if((*it)[0]<=right&&(*it)[1]>right){ // 交错，合并
                right = (*it)[1];
            }else{ // 不相交
                res.push_back(vector<int>{left,right});
                left = (*it)[0];
                right = (*it)[1];
            }
        }

        res.push_back(vector<int>{left,right});
        return res;
    }
};

bool compare(vector<int>&a,vector<int>&b){
    if(a[0]<b[0]){
        return true;
    }else if(a[0]==b[0]){
        return a[1]>b[1];
    }else{
        return false;
    }
}