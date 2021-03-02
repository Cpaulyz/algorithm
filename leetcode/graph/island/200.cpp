// https://leetcode-cn.com/problems/number-of-islands/
// Created by admin on 2021/3/2.
//
using namespace std;
#include <vector>
#include <numeric>
class UF {
public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;

public:
    UF(int _n): n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int findset(int x) {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    }

    void unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
    }

    bool isRoot(int x){
        return fa[x]==x;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int line = grid.size();
        int col = grid[0].size();
        UF uf(line*col);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]=='1'){
                    int up = i==0?0:grid[i-1][j]-'0';
                    int left = j==0?0:grid[i][j-1]-'0';
                    if(up==1){
                        uf.unite(i*col+j,(i-1)*col+j);
                    }
                    if(left==1){
                        uf.unite(i*col+j,i*col+j-1);
                    }
                }
            }
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]=='1'&&uf.isRoot(i*col+j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){
    vector<vector<char>> v;
    v.push_back({'1'});
    v.push_back({'1'});
    Solution s;
    s.numIslands(v);
}