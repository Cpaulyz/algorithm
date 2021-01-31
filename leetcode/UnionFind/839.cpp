// https://leetcode-cn.com/problems/similar-string-groups/
// Created by admin on 2021/1/31.
//

using namespace std;
#include <string>
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
    int groups(){
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if(fa[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        UF uf(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = i+1; j < strs.size(); ++j) {
                if(isSimilar(strs[i],strs[j])){
                    uf.unite(i,j);
                }
            }
        }
        return uf.groups();
    }

    bool isSimilar(string& str1,string& str2){
        char diff1[2];
        char diff2[2];
        int numDifferent = 0;
        if(str1.size()!=str2.size()){
            return false;
        }
        for (int i = 0; i < str1.size(); ++i) {
            if(str1.at(i)!=str2.at(i)){
                if(numDifferent==2){
                    return false;
                }else{
                    diff1[numDifferent] = str1.at(i);
                    diff2[numDifferent] = str2.at(i);
                    numDifferent++;
                }
            }
        }
        if(numDifferent==0){
            return true;
        }else if(numDifferent==2){
            if(diff1[0]==diff2[1]&&diff2[0]==diff1[1]){
                return true;
            }else{
                return false;
            }
        } else{
            return false;
        }
    }
};