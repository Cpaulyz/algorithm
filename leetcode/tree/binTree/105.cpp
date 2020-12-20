// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder,inorder,0,preorder.size(),0,inorder.size());
    }
    TreeNode *build(vector<int> &preorder, vector<int> &inorder,int preStart,int preEnd,int inStart,int inEnd){
        if(preStart>=preEnd){
            return NULL;
        }
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int i;
        for ( i = 0; i < inEnd-inStart ; ++i) {
            if(inorder[inStart+i]==rootVal){
                break;
            }
        }
        root->left = build(preorder,inorder,preStart+1,preStart+1+i,inStart,inStart+i);
        root->right = build(preorder,inorder,preStart+1+i,preEnd,inStart+i+1,inEnd);
        return root;
    }
};