// https://leetcode-cn.com/problems/merge-k-sorted-lists/
// Created by admin on 2021/3/6.
// n个指针+优先队列
using namespace std;
#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct cmp{
    bool operator() ( ListNode * a, ListNode * b ){//默认是less函数
        if(a== nullptr){
            return false;
        }else if(b== nullptr){
            return true;
        }else{
            return a->val > b->val;
        }
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* head = nullptr;
        ListNode* res = nullptr;
        priority_queue<ListNode*,vector<ListNode*>,cmp> queue;
        vector<ListNode*> nodes(lists.size());
        for (int i = 0; i < lists.size(); ++i) {
            nodes[i] = lists[i];
            queue.push(nodes[i]);
        }
        while(head==nullptr){
            if(queue.empty()){
                return nullptr;
            }
            head = queue.top();
            queue.pop();
        }
        res = head;
        if(head->next!= nullptr){
            queue.push(head->next);
        }
        while (!queue.empty()){
            head->next = queue.top();
            head = head->next;
            queue.pop();
            if(head->next!= nullptr){
                queue.push(head->next);
            }
        }
        return res;
    }
};