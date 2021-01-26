// https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/
// Created by admin on 2021/1/20.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;
#include <vector>
#include <string>
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            return new TreeNode(val);
        }
        if(val>root->val){
            if(root->right!=NULL){
                insertIntoBST(root->right,val);
            }else{
                root->right=new TreeNode(val);
            }
        }else if(val<root->val){
            if(root->left!=NULL){
                insertIntoBST(root->left,val);
            }else{
                root->left=new TreeNode(val);
            }
        }
        return root;
    }
};