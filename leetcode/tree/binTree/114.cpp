// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
// Created by admin on 2020/12/20.
//

#include <iostream>

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
    void flatten(TreeNode *root) {
        flat(root);
    }

    // flat一个树，返回末节点
    TreeNode* flat(TreeNode* node){
        if(node==NULL){
            return NULL;
        }
        TreeNode* llast = flat(node->left);
        TreeNode* rlast = flat(node->right);
        TreeNode* temp = node->right;
        if(llast==NULL&&rlast==NULL){ // 左右皆无
            return node;
        }else if(llast==NULL&&rlast!=NULL){
            return rlast;
        }else if(llast!=NULL&&rlast==NULL){
            node->right = node->left;
            node->left = NULL;
            return llast;
        }else{
            node->right = node->left;
            node->left = NULL;
            llast->right = temp;
            return rlast;
        }
    }
};
