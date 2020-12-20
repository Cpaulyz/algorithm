// https://leetcode-cn.com/problems/maximum-binary-tree/
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return construct(nums,0,nums.size());
    }

    TreeNode *construct(vector<int> &nums,int start,int end) {
        if(start>=end){
            return NULL;
        }
        int index = findMaxIndex(nums,start,end);
        TreeNode* node = new TreeNode(nums[index]);
        node->left = construct(nums,start,index);
        node->right = construct(nums,index+1,end);
        return node;
    }

    int findMaxIndex(vector<int> &nums,int start,int end){
        int i,index,max=-99999;
        for(i = start;i<end;++i){
            if(nums[i]>max){
                index = i;
                max = nums[i];
            }
        }
        return index;
    }
};