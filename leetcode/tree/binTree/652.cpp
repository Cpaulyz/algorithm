// https://leetcode-cn.com/problems/find-duplicate-subtrees/
// Created by admin on 2020/12/26.
// https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/2.3-shou-ba-shou-shua-er-cha-shu-xun-lian-di-gui-si-wei/er-cha-shu-xi-lie-3
// 和序列化有关

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        unordered_map<string,int> map;
        vector<TreeNode*> res;
        stringTree(root,map,res);
        return res;
    }

    string stringTree(TreeNode *node,unordered_map<string,int> &map,vector<TreeNode*> &res){
        if(node==NULL){
            return "#";
        }
        string lhs = stringTree(node->left,map,res);
        string rhs = stringTree(node->right,map,res);
        string tree =to_string(node->val)+","+lhs+","+rhs;
        if(map[tree]==1){
            res.push_back(node);
        }
        map[tree]++;
        return tree;
    }
};

int main(){
    TreeNode* a = new TreeNode(4);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(4);
    TreeNode* d = new TreeNode(3);
    TreeNode* e = new TreeNode(5);
    a->left = b;
    c->left = d;
    e->left = a;
    e->right= c;
    Solution s;
    s.findDuplicateSubtrees(e);

}