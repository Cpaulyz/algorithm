// https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/
// Created by admin on 2021/7/31.
// DFS建表，排序

using namespace std;

#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node {
    int x;
    int y;
    int val;

    Node(int x, int y, int val) : x(x), y(y), val(val) {};
};

bool cmp(Node *a, Node *b);

class Solution {
    vector<Node *> nodes;
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end(), cmp);
        vector <vector<int>> res;
        vector<int> tmp;
        int currX = nodes[0]->x;
        tmp.push_back(nodes[0]->val);
        for (int i = 1; i < nodes.size(); ++i) {
            if (nodes[i]->x != currX) {
                res.push_back(tmp);
                tmp = vector<int>();
                currX = nodes[i]->x;
            }
            tmp.push_back(nodes[i]->val);
        }
        res.push_back(tmp);
        return res;
    }

    void dfs(TreeNode *node, int x, int y) {
        if (node == nullptr) {
            return;
        }
        nodes.push_back(new Node(x, y, node->val));
        dfs(node->left, x - 1, y + 1);
        dfs(node->right, x + 1, y + 1);
    }


};

bool cmp(Node *a, Node *b) {
    if (a->x == b->x) {
        if (a->y == b->y) {
            return a->val < b->val;
        } else {
            return a->y < b->y;
        }
    } else {
        return a->x < b->x;
    }
}