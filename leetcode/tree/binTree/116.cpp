// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
// Created by admin on 2020/12/20.
//
#include <iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }else{
            connectNode(root->left,root->right);
        }
        return root;
    }

    void connectNode(Node* left,Node* right){
        if(left==NULL||right==NULL){
            return;
        }
        left->next = right;
        connectNode(left->left,left->right);
        connectNode(left->right,right->left);
        connectNode(right->left,right->right);
    }
};
