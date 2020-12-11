//https://leetcode-cn.com/problems/remove-covered-intervals/
//https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/qu-jian-wen-ti-he-ji

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(vector<int>&a,vector<int>&b);
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int left,right,all;
        all = intervals.size();
        left = intervals[0][0];
        right = intervals[0][1];
        for (vector<vector<int>>::iterator it = intervals.begin()+1; it != intervals.end(); it++){
            if((*it)[1]<=right){
               all--;
            }else{
                left = (*it)[0];
                right = (*it)[1];
            }
        }
        return all;
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

int main(){
    vector<int> a{1,4};
    vector<int> b{3,6};
    vector<int> c{2,8};
    vector<vector<int>> d;
    d.push_back(a);
    d.push_back(b);
    d.push_back(c);
    Solution s;
    cout << s.removeCoveredIntervals(d);

}