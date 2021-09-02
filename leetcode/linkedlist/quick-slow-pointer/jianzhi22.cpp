// https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
// Created by 陈彦泽 on 2021/9/2.
// 快慢双指针

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        for(int i=0;i<k;++i){
            fast = fast->next;
        }
        while(fast!=NULL){
            fast = fast->next;
            head = head->next;
        }
        return head;
    }
};