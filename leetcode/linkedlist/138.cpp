// https://leetcode-cn.com/problems/copy-list-with-random-pointer/
// Created by admin on 2021/7/22.
// 开个哈希表就完事
using namespace std;
#include <vector>
#include <unordered_map>
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> node_map;
        Node* pre = new Node(head->val);
        pre->random = head->random;
        node_map[head] =pre;
        for(Node* cur = head->next;cur!=NULL;cur=cur->next){
            Node* tmp = new Node(cur->val);
            tmp->random = cur->random;
            node_map[cur] =tmp;
            pre->next = tmp;
            pre =tmp;
        }
        for(Node* cur = node_map[head];cur!=NULL;cur=cur->next){
            if(cur->random!=NULL) {
                cur->random = node_map[cur->random];
            }
        }
        return node_map[head];
    }
};