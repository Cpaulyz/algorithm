// https://leetcode-cn.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        return isValid(root,NULL,NULL);
    }
    bool isValid(TreeNode* root,TreeNode* min,TreeNode* max) {
        if(root==NULL){
            return true;
        }
        if(min==NULL&&max==NULL){
            return isValid(root->left,NULL,root)&&isValid(root->right,root,NULL);
        }else if(min!=NULL&&max==NULL){
            return root->val>min->val&&
                    isValid(root->left,min,root)&&
                    isValid(root->right,root,NULL);
        }else if(min==NULL&&max!=NULL){
            return root->val<max->val&&
                    isValid(root->left,NULL,root)&&
                    isValid(root->right,root,max);
        }else{ // all not NULL
            return root->val>min->val&&
                    root->val<max->val&&
                    isValid(root->left,min,root)&&
                    isValid(root->right,root,max);
        }
    }
};