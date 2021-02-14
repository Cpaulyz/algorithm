// https://leetcode-cn.com/problems/couples-holding-hands/
// Created by admin on 2021/2/14.
// https://leetcode-cn.com/problems/couples-holding-hands/solution/liang-chong-100-de-jie-fa-bing-cha-ji-ta-26a6/
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

    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        UF uf(row.size()/2);
        for (int i = 0; i < row.size(); i+=2) {
            uf.unite(row[i],row[i+1]);
        }
        return row.size()/2 - uf.comp_cnt;
    }
};

int main(){
    Solution s;
    vector<int> v{0,2,1,3};
    s.minSwapsCouples(v);
}