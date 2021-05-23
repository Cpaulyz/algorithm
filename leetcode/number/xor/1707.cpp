// https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/
// Created by admin on 2021/5/23.
// 1. 用字典树来找最大值
// 2. 因为有limit，这里的小技巧是把查询按照limit排序，插入字典树中查找
// 3. 一开始一直超时，因为bool cmp(vector<int>&a,vector<int>&b)的参数写成了不带&的，这也是一个优化点
using namespace std;
#include <vector>
#include <algorithm>

class Node{
public:
    Node* sub[2];
    int num;
    int offset=31;
    Node(){sub[0]=sub[1]= nullptr;}

    void addNode(int n){
        Node* tmp = this;
        for (int i = offset; i >=0 ; --i) {
            int ptr = ((1<<i)&n)==0?0:1;
            if(tmp->sub[ptr]== nullptr){
                tmp->sub[ptr] = new Node();
            }
            tmp = tmp->sub[ptr];
        }
        tmp->num = n;
    }

    int getRes(int n){
        Node* tmp = this;
        for (int j = offset; j >=0 ; --j) {
            int ptr = ((1<<j)&n)==0?1:0;
            if(tmp->sub[ptr]!= nullptr){
                tmp = tmp->sub[ptr];
            }else{
                tmp = tmp->sub[1-ptr];
            }
        }
        return tmp->num ^ n;
    }
};
bool cmp(vector<int>&a,vector<int>&b);

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); ++i) {
            queries[i].push_back(i);
        }
        Node* root = new Node();
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end(),cmp);
        int index = 0;
        // 开始算答案
        vector<int> res(queries.size());
        for (auto q:queries) {
            int target = q[0];
            int limit = q[1];
            while (index<nums.size()&&nums[index]<=limit){
                // 构造前缀树
                root->addNode(nums[index++]);
            }
            if(index==0){
                res[q[2]] = -1;
            }else{
                res[q[2]]  = root->getRes(target);
            }
        }
        return res;
    }
};

bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}

int main(){
    Solution s;
    vector<int> a{0,1,2,3,4};
    vector<vector<int>> q{{3,1},{1,3},{5,6}};
    s.maximizeXor(a,q);
}