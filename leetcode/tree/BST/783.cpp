// https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
// Created by admin on 2021/4/13.
// 中序遍历

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
    int prev;
    int res;
public:
    int minDiffInBST(TreeNode* root) {
        prev = -1;
        res = 10000000;
        helper(root);
        return res;
    }

    void helper(TreeNode* node){
        if(node==nullptr){
            return ;
        }
        helper(node->left);
        if(prev==-1){
            prev = node->val;
        }else{
            res = min(node->val-prev,res);
            prev = node->val;
        }
        helper(node->right);

    }
};