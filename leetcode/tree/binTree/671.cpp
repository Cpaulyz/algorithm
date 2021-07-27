// https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/
// Created by admin on 2021/7/27.
// DFS

using namespace std;

#include <vector>
#include <unordered_map>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int res = -1;
    int minVal;
public:
    int findSecondMinimumValue(TreeNode *root) {
        minVal = root->val;
        search(root);
        return res;
    }

    void search(TreeNode* node){
        if(node== nullptr){
            return;
        }else{
            if(node->val>minVal&&(node->val<res||res==-1)){
                res = node ->val;
            }
            search(node->left);
            search(node->right);
        }
    }

};