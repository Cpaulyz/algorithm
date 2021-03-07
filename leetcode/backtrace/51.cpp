// https://leetcode-cn.com/problems/n-queens/
// Created by admin on 2021/3/7.
// 经典回溯
using namespace std;
#include <vector>
#include <string>

class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n,string(n,'.'));
        recall(v,0);
        return res;
    }

    void recall(vector<string>& line,int row){
        if(row==line.size()){
            res.push_back(vector<string>(line.begin(),line.end()));
            return;
        }
        for (int col = 0; col < line.size(); ++col) {
            if(valid(line,row,col)){
                line[row][col] = 'Q';
                recall(line,row+1);
                line[row][col] = '.';
            }
        }
    }

    bool valid(vector<string>& line,int row,int col){
        // check line;
        for (int i = 0; i < row; ++i) {
            if(line[i][col]=='Q'){
                return false;
            }
        }
        // 一行里肯定不会重复
        // check对角
        for (int i = 0; i < line.size(); ++i) {
            int tmp = abs(col-i);
            int tmpRow = row - tmp;
            if(tmpRow>=0){
                if(line[tmpRow][i]=='Q'){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    s.solveNQueens(4);
}