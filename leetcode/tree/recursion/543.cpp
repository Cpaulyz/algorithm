// https://leetcode-cn.com/problems/diameter-of-binary-tree/
// Created by 陈彦泽 on 2021/9/9.
// 从低向上递归

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
class Solution {
    int res = -99999;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res-1;// 因为计算是节点数，路径要-1
    }

    // 返回以node为根的最长路径(节点数)
    int dfs(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        int l = dfs(node->left);
        int r = dfs(node->right);
        res = max(res,1+l+r);
        cout << node->val << " "<<res<< endl;
        return 1+max(l,r);
    }
};