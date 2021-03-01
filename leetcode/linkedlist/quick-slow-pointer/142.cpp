// https://leetcode-cn.com/problems/linked-list-cycle-ii/
// Created by admin on 2021/3/1.
// 总长 = a + b
// 第一次相遇：slow_step , quick_step=2*slow_step
// quick_step-slow_step = slow_step = nb
// 第一次相遇到第二次相遇，慢指针又走了b
// 事实上，只要求出b，就可以重新起一组快慢指针，差距b，往前走，第一次q=s时就是七点

using namespace std;
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
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