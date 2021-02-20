// https://leetcode-cn.com/problems/reverse-linked-list/
// Created by admin on 2021/2/20.
//
using namespace std;
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 迭代版本
//    ListNode *reverseList(ListNode *head) {
//        if(head==NULL){
//            return NULL;
//        }
//        ListNode* pre = NULL;
//        ListNode* newhead = head;
//        while (newhead->next!=NULL){
//            ListNode* tmp = newhead->next;
//            newhead->next = pre;
//            pre = newhead;
//            newhead = tmp;
//        }
//        newhead->next = pre;
//        return newhead;
//    }

    // 递归版本
    ListNode *reverseList(ListNode *head) {
        if(head==NULL){
            return NULL;
        }else if(head->next==NULL){
            return head;
        }
        ListNode* newhead = head;
        ListNode* nxt = reverseList(head->next);
        newhead->next->next = newhead;
        newhead->next=NULL;
        return newhead;
    }
};