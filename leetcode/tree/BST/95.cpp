// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
// Created by admin on 2021/1/26.
// 96的升级版
// 运用dp，降低时间复杂度

using namespace std;
#include <vector>
#include <string>
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
public:

    vector<vector<vector<TreeNode*>>> dp;

    vector<TreeNode *> generateTrees(int n) {
        dp = vector<vector<vector<TreeNode*>>>(n+1,vector<vector<TreeNode*>>(n+1));
        return generate(1,n);
    }
    vector<TreeNode *> generate(int lo,int hi) {
        vector<TreeNode*> res;
        if(lo>hi){
            res.push_back(NULL);
            return res;
        }else{
            if(dp[lo][hi].size()!=0){
                return dp[lo][hi];
            }
        }
        for (int i = lo; i <= hi; ++i) { // i是根节点
            vector<TreeNode*> left = generate(lo,i-1);
            vector<TreeNode*> right = generate(i+1,hi);
            for (TreeNode* l:left){
                for(TreeNode* r:right){
                    TreeNode* n = new TreeNode(i,l,r);
                    res.push_back(n);
                }
            }
        }
        dp[lo][hi]=res;
        return res;
    }
};

int main(){
    Solution s;
    s.generateTrees(5);
}