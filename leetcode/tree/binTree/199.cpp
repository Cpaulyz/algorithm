// https://leetcode-cn.com/problems/binary-tree-right-side-view/
// Created by admin on 2021/3/1.
// 无法确定树的形状，所以采用层次遍历，取右边第一个即可

using namespace std;
#include <vector>
#include <deque>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> lvl;
        lvl.push_back(root);
        while (!lvl.empty()){
            int size = lvl.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* n = lvl.back();
                lvl.pop_back();
                if(i==0){
                    res.push_back(n->val);
                }
                if(n->right) lvl.push_front(n->right);
                if(n->left) lvl.push_front(n->left);
            }
        }
        return res;
    }
};