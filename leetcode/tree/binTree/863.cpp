// https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/
// Created by admin on 2021/7/29.
// DFS建图，BFS搜索

using namespace std;

#include <vector>
#include <unordered_map>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<int, vector<int>> graph;
    unordered_map<int,int> visited;
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        // build graph
        dfs(root);
        // bfs search
        queue<int> q;
        q.push(target->val);
        visited[target->val] = true;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            int sz = q.size();
            for (int j = 0; j < sz; ++j) {
                int n = q.front();
                q.pop();
                for(int node:graph[n]){
                    if(!visited[node]){
                        visited[node] = true;
                        q.push(node);
                    }
                }
            }
        }
        while (!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }

    TreeNode* dfs(TreeNode*  node){
        if(node==NULL){
            return NULL;
        }
        visited[node->val] = false;
        TreeNode* tmp =dfs(node->left);
        addGraph(tmp,node);
        tmp = dfs(node->right);
        addGraph(tmp,node);
        return node;
    }

    void addGraph(TreeNode* a,TreeNode* b){
        if(a!=NULL&&b!=NULL){
            if(graph.count(a->val)==0){
                graph[a->val] = vector<int>();
            }
            graph[a->val].push_back(b->val);
            if(graph.count(b->val)==0){
                graph[b->val] = vector<int>();
            }
            graph[b->val].push_back(a->val);
        }
    }
};