// https://leetcode-cn.com/problems/binary-search-tree-iterator/
// Created by admin on 2021/3/28.
// 方法一：直接中序遍历，保存数组，扁平化处理
// 方法二：二叉树中序遍历迭代版

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> nodes;
public:
    BSTIterator(TreeNode* root) {
        nodes.push(root);
        while(root->left!=nullptr){
            root = root->left;
            nodes.push(root);
        }
    }

    int next() {
        TreeNode* node = nodes.top();
        nodes.pop();
        int res = node->val;
        node = node->right;
        while(node!=nullptr){
            nodes.push(node);
            node = node->left;
        }
        return res;
    }

    bool hasNext() {
        return !nodes.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */