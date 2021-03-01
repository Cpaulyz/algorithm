// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
// Created by admin on 2021/3/1.
// 层次遍历

using namespace std;
#include <vector>
#include <queue>

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
    vector <vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode*> lvl;
        vector<vector<int>> res;
        if(root== nullptr){
            return res;
        }
        lvl.push(root);
        int size = 1;
        while (true){
            vector<int> tmp;
            int newsize = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* n = lvl.front();
                lvl.pop();
                tmp.push_back(n->val);
                if(n->left!= nullptr) {
                    lvl.push(n->left);
                    newsize++;
                }
                if(n->right!= nullptr) {
                    lvl.push(n->right);
                    newsize++;
                }
            }
            if(!tmp.empty())
                res.push_back(tmp);
            else
                break;
        }
        return res;
    }
};