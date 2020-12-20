// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Created by admin on 2020/12/20.
//


#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (postStart >= postEnd) {
            return NULL;
        }
        int rootVal = postorder[postEnd - 1];
        TreeNode *root = new TreeNode(rootVal);
        int i;
        for (i = 0; i < inEnd - inStart; ++i) {
            if (inorder[inStart + i] == rootVal) {
                break;
            }
        }
        root->left = build( inorder,postorder,inStart, inStart + i,postStart,postStart+i);
        root->right = build( inorder,postorder,inStart + i+1, inEnd,postStart+i,postEnd-1);
        return root;
    }
};