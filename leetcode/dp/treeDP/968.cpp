// https://leetcode-cn.com/problems/binary-tree-cameras/
// Created by admin on 2021/6/3.
// 树形dp,记忆化搜索,否则超时

using namespace std;

#include <vector>
#include <unordered_map>

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
    vector<unordered_map<TreeNode*,int>> map;
public:
    int minCameraCover(TreeNode* root) {
        map = vector<unordered_map<TreeNode*,int>>(3,unordered_map<TreeNode*,int>());
        return helper(root,2);

    }

    // 三种状态
    // 0. 该节点必须放摄像机
    // 1. 该节点被父节点看到，可有可无
    // 2. 没被照到，该节点要放或者子节点之一放
    int helper(TreeNode* node,int type){
        if(node==nullptr){
            return 0;
        }
        if(map[type].count(node)!=0){
            return map[type][node];
        }
        int res;
        if(type==0){
            res =  1+helper(node->left,1)+helper(node->right,1);
        }else if(type==1){
            res = min(helper(node->left,2)+helper(node->right,2)
                    ,1+helper(node->left,1)+helper(node->right,1));
        }else{
            if(node->left==nullptr && node->right==nullptr){
                res =  1;
            }else{
                res = 1+helper(node->left,1)+helper(node->right,1);
                if(node->right!=nullptr){
                    res = min(res,helper(node->left,2)+helper(node->right,0));
                }
                if(node->left!=nullptr){
                    res = min(res,helper(node->left,0)+helper(node->right,2));
                }
            }
        }
        map[type][node] = res;
        return res;
    }
};