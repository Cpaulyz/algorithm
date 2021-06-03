// https://blog.csdn.net/qq_35307005/article/details/108172832
// Created by admin on 2021/6/3.
// 预推免第二题
/*
二叉树搜索。给一个二叉树（节点数小于等于64，节点值不重复）的前序中序，
 再给一个整数，输出从根节点到叶子节点路径权值总和等于该数的路径总数。
（这是我写的样例）
输入：
7 10
1 2 4 7 5 3 6
7 4 2 5 1 6 3
输出：
1
 */

using namespace std;

#include <vector>
#include <iostream>

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int n) : val(n) {
        left = right = nullptr;
    }
};

class Solution{
    int res = 0;
public:
    Node *construct(vector<int> &pre, int preStart, int preEnd, vector<int> &mid, int midStart, int midEnd) {
        if (preStart >= preEnd) {
            return nullptr;
        }
        Node *node = new Node(pre[preStart]);
        int m;
        for (m = midStart; m < midEnd; m++) {
            if (mid[m] == pre[preStart]) {
                break;
            }
        }
        node->left = construct(pre, preStart + 1, preStart + m - midStart + 1, mid, midStart, m);
        node->right = construct(pre, preStart + m - midStart + 1, preEnd, mid, m + 1, midEnd);
        return node;
    }

    int count(Node* root,int m){
        res = 0;
        dfs(root,0,m);
        return res;
    }

    void dfs(Node* node,int sum,int m){
        if(node== nullptr){
            return ;
        }
        sum += node->val;
        if(sum==m){
            res++;
        }
        dfs(node->left,sum,m);
        dfs(node->right,sum,m);
        sum -= node->val;
    }
};


int main() {
    int m, n;
    cin >> m >> n;
    vector<int> pre;
    vector<int> mid;
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        pre.push_back(tmp);
    }
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        mid.push_back(tmp);
    }
    Solution s;
    Node *root = s.construct(pre, 0, m, mid, 0, m);
    cout << s.count(root,n);

}

