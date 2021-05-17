// https://leetcode-cn.com/problems/cousins-in-binary-tree/submissions/
// Created by admin on 2021/5/17.
// BFS

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
    bool isCousins(TreeNode* root, int x, int y) {
        int deep_x,deep_y;
        int par_x,par_y;
        int deep = 0;
        queue<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            int sz = s.size();
            for(int i=0;i<sz;++i){
                TreeNode* tmp = s.front();
                s.pop();
                if(tmp->left!=nullptr){
                    s.push(tmp->left);
                    if(tmp->left->val==x){
                        deep_x = deep;
                        par_x = tmp->val;
                        cout << "x " << deep_x << " " << par_x <<endl;
                    }
                    if(tmp->left->val==y){
                        deep_y = deep;
                        par_y = tmp->val;
                        cout << "y " << deep_y << " " << par_y <<endl;
                    }
                }
                if(tmp->right!=nullptr){
                    s.push(tmp->right);
                    if(tmp->right->val==x){
                        deep_x = deep;
                        par_x = tmp->val;
                        cout << "x " << deep_x << " " << par_x <<endl;
                    }
                    if(tmp->right->val==y){
                        deep_y = deep;
                        par_y = tmp->val;
                        cout << "y " << deep_y << " " << par_y <<endl;
                    }
                }
            }
            deep++;
        }
        return (deep_x==deep_y)&&(par_x!=par_y);
    }
};