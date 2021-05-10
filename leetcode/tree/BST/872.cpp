// https://leetcode-cn.com/problems/leaf-similar-trees/
// Created by admin on 2021/5/10.
// 顺序找叶子节点，dfs

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
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1,l2;
        dfs(root1,l1);
        dfs(root2,l2);
        bool res = false;
        if(l1.size()==l2.size()){
            res = true;
            for(int i=0;i<l1.size();++i){
                if(l1[i]!=l2[i]){
                    res = false;
                    break;
                }
            }
        }
        return res;
    }
    void dfs(TreeNode* node,vector<int> &leaves){
        if(node->left==nullptr&&node->right==nullptr){
            leaves.push_back(node->val);
        }else{
            if(node->left!=nullptr){
                dfs(node->left,leaves);
            }
            if(node->right!=nullptr){
                dfs(node->right,leaves);
            }
        }
    }
};