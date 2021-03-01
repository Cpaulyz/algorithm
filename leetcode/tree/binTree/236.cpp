// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Created by admin on 2021/3/1.
// DFS

using namespace std;

#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* ans;

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        find(root,p,q);
        return ans;
    }
    bool find(TreeNode *root, TreeNode *p,TreeNode* q) {
        if(root==NULL){
            return false;
        }
        bool left = find(root->left,p,q);
        bool right = find(root->right,p,q);
        bool self = root==q||root==p;
        if((left&&right)||(left&&self)||(right&&self)){
            ans = root;
            return true;
        }
        return left||right||self;
    }
};