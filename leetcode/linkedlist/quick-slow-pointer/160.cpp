// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
// Created by admin on 2021/3/1.
// 双指针，借鉴142，官方解答更好
using namespace std;
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        while (a->next!=NULL){
            a = a->next;
        }
        a->next = headA; // 记录，最后要复原
        // 之后类似142，进行判断，起点是B的头
        ListNode* res = detectCycle(headB);
        a->next = NULL; // 还原
        return res;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *quick = head;
        ListNode *slow = head;
        do{
            if(quick==NULL){
                return NULL;
            }else{
                quick = quick->next;
            }
            if(quick==NULL){
                return NULL;
            }else{
                quick = quick->next;
            }
            slow = slow->next;
        } while (quick!=slow); // 第一次相遇
        int b = 0; // 环的长度
        do{
            quick = quick->next;
            quick = quick->next;
            slow = slow->next;
            b++;
        } while (quick!=slow); // 第二次相遇
        return find(head,b);
    }

    ListNode *find(ListNode *head,int b){
        ListNode* q = head;
        ListNode* s = head;
        for (int i = 0; i < b; ++i) {
            q = q->next;
        } // 初始化相差
        while (q!=s){
            q = q->next;
            s = s->next;
        }
        return q;
    }
};