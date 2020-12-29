// https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
// Created by admin on 2020/12/29.
//
#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        sub(root);
        return root;
    }

    void sub(TreeNode* node){
        if(node==NULL){
            return;
        }
        sub(node->right);
        sum+=node->val;
        node->val=sum;
        sub(node->left);
    }
};