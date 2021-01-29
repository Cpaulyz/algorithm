// https://leetcode-cn.com/problems/path-with-minimum-effort/
// Created by admin on 2021/1/29.
// 「并查集」：我们可以将所有边按照长度进行排序并依次添加进并查集，直到左上角和右下角连通为止。
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>
#include "math.h"

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

struct Edge{
    int from,to,val;
    Edge(int _from,int _to,int _val):from(_from),to(_to),val(_val){}
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int h = heights.size();
        int w = heights[0].size();
        UF uf(h*w);
        vector<Edge> edges;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                int id = i*w+j;
                if(i>0){
                    edges.emplace_back(id-w,id,abs(heights[i-1][j]-heights[i][j]));
                }
                if(j>0){
                    edges.emplace_back(id-1,id,abs(heights[i][j-1]-heights[i][j]));
                }
            }
        }
        sort(edges.begin(),edges.end(),[](Edge x,Edge y){return x.val<y.val;});
        for(Edge edge:edges){
            uf.unite(edge.from,edge.to);
            if(uf.connected(0,h*w-1)){
                return edge.val;
            }
        }
        return 0;
    }
};