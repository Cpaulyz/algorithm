#include <iostream>
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
    int deep;
    int TreeDepth(TreeNode* pRoot)
    {
        this->deep= 0;
        dfs(pRoot1);
        return this->deep;
    }
    void dfs(TreeNode* pRoot,int deep){
        if(pRoot==NULL){
            return;
        }
        if(deep> this->deep){
            this->deep = deep;
        }
        dfs(pRoot->left,deep+1);
        dfs(pRoot->right,deep+1);
    }
};
