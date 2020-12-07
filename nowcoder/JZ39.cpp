//https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&&tqId=11192&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <iostream>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    unordered_map<TreeNode*,int> map;
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL){
            return true;
        }else if((abs(getDeep(pRoot->left)-getDeep(pRoot->right)))>1){
            return false;
        }else{
            return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
        }
    }
    int getDeep(TreeNode* node){
        if(map.count(node)>0){
            return map.count(node);
        }
        if(node==NULL){
            return 0;
        }
        int res = max(getDeep(node->left),getDeep(node->right))+1;
        map[node] = res;
        return res;
    }
};