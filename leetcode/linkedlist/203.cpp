// https://leetcode-cn.com/problems/remove-linked-list-elements/submissions/
// Created by admin on 2021/6/5.
// 遍历即可

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        while(cur!=nullptr&&cur->val==val){
            cur = cur->next;
        }
        ListNode* newHead = cur;
        if(cur!=nullptr){
            while(cur->next!=nullptr){
                if(cur->next->val==val){
                    cur->next = cur->next->next;
                }else{
                    cur = cur->next;
                }
            }
        }
        return newHead;
    }
};