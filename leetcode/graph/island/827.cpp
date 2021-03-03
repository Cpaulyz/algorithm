// https://leetcode-cn.com/problems/making-a-large-island/
// Created by admin on 2021/3/3.
// 并查集解法
using namespace std;
#include <vector>
#include <numeric>
#include <unordered_map>
class UF{
public:
    vector<int> fa;
    vector<int> area;
    UF(int n):fa(n),area(n,1){
        iota(fa.begin(),fa.end(),0);
    }
    int findset(int x){
        return fa[x]==x?x:findset(fa[x]);
    }
    int unite(int x,int y){
        int xfa = findset(x);
        int yfa = findset(y);
        if(xfa!=yfa){
            fa[xfa] = yfa;
            area[yfa] += area[xfa];
            return area[yfa];
        }else{
            return 0;
        }
    }
    int getArea(int x){
        return area[findset(x)];
    }
    bool connected(int x,int y){
        return findset(x)==findset(y);
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        UF uf(grid.size()*grid[0].size());
        unordered_map<int,int> map;
        int line = grid[0].size();
        int maxArea = 1;
        // first time, union
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]==1){
                    int left = j==0?0:grid[i][j-1];
                    int up = i==0?0:grid[i-1][j];
                    if(left) {
                        int tmp = uf.unite(i*line+j,i*line+j-1);
                        maxArea = max(maxArea,tmp);
                    }
                    if(up){
                        int tmp =uf.unite(i*line+j,(i-1)*line+j);
                        maxArea = max(maxArea,tmp);
                    }
                }
            }
        }
        // second time, try reverse
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]==0) {
                    int tmp = 1;
                    int left = j==0?0:grid[i][j-1];
                    int right = j==grid[0].size()-1?0:grid[i][j+1];
                    int up = i==0?0:grid[i-1][j];
                    int down = i==grid.size()-1?0:grid[i+1][j];
                    if(left!=0)  {
                        int fa = uf.findset(i*line+j-1);
                        if(map[fa]==0){
                            tmp+=uf.getArea(fa);map[fa]++;
                        }
                    }
                    if(right!=0)  {
                        int fa = uf.findset(i*line+j+1);
                        if(map[fa]==0){
                            tmp+=uf.getArea(fa);map[fa]++;
                        }
                    }
                    if(up!=0)  {
                        int fa = uf.findset((i-1)*line+j);
                        if(map[fa]==0){
                            tmp+=uf.getArea(fa);map[fa]++;
                        }
                    }
                    if(down!=0)  {
                        int fa = uf.findset((i+1)*line+j);
                        if(map[fa]==0){
                            tmp+=uf.getArea(fa);map[fa]++;
                        }
                    }
                    maxArea = max(maxArea,tmp);
                    map.clear();
                }
            }
        }
        return maxArea;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v;
    v.push_back({1,1});
    v.push_back({0,1});
    s.largestIsland(v);
}