// https://leetcode-cn.com/problems/delete-node-in-a-bst/
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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val>key){
            root->left =  deleteNode(root->left,key);
        }else if(root->val<key){
            root->right = deleteNode(root->right,key);
        }else{ // ==key
            if(root->left==NULL&&root->right==NULL){
                return NULL;
            }else if(root->left==NULL){
                // 找右边最小的来替代
                TreeNode* tmp = root->right;
                while (tmp->left!=NULL){
                    tmp = tmp->left;
                }
                root->val = tmp->val;
                root->right = deleteNode(root->right,tmp->val);
            }else{
                // 找左边最大的来替代
                TreeNode* tmp = root->left;
                while (tmp->right!=NULL){
                    tmp = tmp->right;
                }
                root->val = tmp->val;
                root->left = deleteNode(root->left,tmp->val);
            }
        }
        return root;
    }

};