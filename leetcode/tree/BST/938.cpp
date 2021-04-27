// https://leetcode-cn.com/problems/range-sum-of-bst/
// Created by admin on 2021/4/27.
// 中序+剪枝

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
    int sum;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        dfs(root,low,high);
        return sum;
    }
    void dfs(TreeNode* node,int low,int high){
        if(node==nullptr){
            return;
        }
        dfs(node->left,low,high);
        if(node->val>high){
            return;
        }
        if(node->val>=low){
            sum+=node->val;
        }
        dfs(node->right,low,high);
    }
};