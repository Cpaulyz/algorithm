// https://leetcode-cn.com/problems/sliding-puzzle/
// Created by admin on 2021/6/26.
// bfs

using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string ,int> gone1; // 序列1，移动次数
        string init = "";
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                init += to_string(board[i][j]);
            }
        }
        if(init=="123450"){
            return 0; // 特殊情况
        }
        queue<string> curr = queue<string>({init});
        int n = 1;
        while (!curr.empty()){
            int sz = curr.size();
            for (int i = 0; i < sz; ++i) {
                int res = add(gone1,curr,n);
                if(res>0){
                    return res;
                }
            }
            n++;
        }
        return -1;
    }

    int add(unordered_map<string,int>& gone,queue<string>& now,int path){
        string n = now.front();
        now.pop();
        int i=0;
        for (i = 0; n[i]!='0'; ++i);
        string tmp;
        if(i>=3){
            tmp = swap(n,i,i-3);
            if(tmp=="123450"){
                return path;
            }else if(gone.count(tmp)==0){
                gone[tmp] = path;
                now.push(tmp);
            }
        }
        if(i<3){
            tmp = swap(n,i,i+3);
            if(tmp=="123450"){
                return path;
            }else if(gone.count(tmp)==0){
                gone[tmp] = path;
                now.push(tmp);
            }
        }
        if(i%3!=2){
            tmp = swap(n,i,i+1);
            if(tmp=="123450"){
                return path;
            }else if(gone.count(tmp)==0){
                gone[tmp] = path;
                now.push(tmp);
            }
        }
        if(i%3!=0){
            tmp = swap(n,i,i-1);
            if(gone.count(tmp)==0){
                gone[tmp] = path;
                now.push(tmp);
            }
        }
        return 0;
    }

    string swap(string str,int i,int j){
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        return str;
    }
};




