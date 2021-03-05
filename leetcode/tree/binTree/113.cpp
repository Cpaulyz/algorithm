// https://leetcode-cn.com/problems/path-sum-ii/
// Created by admin on 2021/3/5.
//
using namespace std;
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<vector<int>> res;
    vector<int> fa;
    int val = 0;
public:
    vector <vector<int>> pathSum(TreeNode *root, int targetSum) {
        dfs(root,targetSum);
        return res;
    }

    void dfs(TreeNode* node,int target){
        if(node== nullptr){
            return;
        }
        val += node->val;
        fa.push_back(node->val);
        if(node->left== nullptr&&node->right== nullptr){
            if(val==target){
                vector<int> tmp(fa.begin(),fa.end());
                res.push_back(tmp);
            }
        }
        dfs(node->left,target);
        dfs(node->right,target);
        fa.pop_back();
        val-=node->val;
    }

};