// https://leetcode-cn.com/problems/house-robber-iii/
// Created by admin on 2020/12/12.
//

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode *root) {
        vector<int> res = dp(root);
        return max(res[0],res[1]);
    }
    vector<int> dp(TreeNode* root){
        vector<int> res; // 第0位是不包含root，第1位是包含root
        if(root==NULL){
            res = {0,0};
            return res;
        }else{
            vector<int> l = dp(root->left);
            vector<int> r = dp(root->right);
            res = {max(l[0],l[1])+max(r[0],r[1]),root->val+l[0]+r[0]};
            // 不抢，下家可抢可不抢，取决于收益大小
            return res;
        }
    }
};