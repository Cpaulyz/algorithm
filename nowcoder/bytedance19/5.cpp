// https://www.nowcoder.com/questionTerminal/3d1adf0f16474c90b27a9954b71d125d
// Created by admin on 2021/3/8.
// 超时了
// DP解法：https://blog.csdn.net/weixin_42490152/article/details/100105019

using namespace std;
#include <vector>
#include <iostream>

class Solution{
    int res;
public:
    int find(vector<vector<int>>& path){
        res= 9999999;
        vector<int> visited(path.size());
        backtrace(path,visited,0,0);
        return res;
    }

    void backtrace(vector<vector<int>>& path,vector<int>& visited,int pos,int cost){
        // 结束条件
        int end = 1;
        for (int i = 1; i <visited.size() ; ++i) {
            if(visited[i]==0){
                end = 0;
                break;
            }
        }
        if(end==1){
            cost += path[0][pos];
            res = min(res,cost);
            return ;
        }
        for (int i = 1; i < visited.size(); ++i) {
            if(visited[i] == 0){
                visited[i] = 1;
                // bt
                backtrace(path,visited,i,cost+path[pos][i]);
                visited[i] = 0;
            }
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> path;
    for (int i = 0; i < n; ++i) {
        vector<int> tmp;
        for (int j = 0; j < n; ++j) {
            int t;
            cin >> t;
            tmp.push_back(t);
        }
        path.push_back(tmp);
    }
    Solution s;
    cout<< s.find(path) <<endl;
}