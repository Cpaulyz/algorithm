// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        int tmp = node->val;
        if(left>0&&right>0){
            res = max(res,node->val+left+right);
            return node->val+max(left,right);
        }else if(left<0&&right<0){
            res = max(res,node->val);
            return node->val;
        }else{
            res = max(res,node->val+max(left,right));
            return node->val+max(left,right);
        }
    }
};