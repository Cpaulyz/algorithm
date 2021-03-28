// https://leetcode-cn.com/problems/rotate-list/
// Created by admin on 2021/3/28.
//

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        int size = 0;
        ListNode* curr = head;
        ListNode* tail;
        while(curr!=nullptr){
            tail=curr;
            curr=curr->next;
            size++;
        }
        k = k%size;
        if(k==0){
            return head;
        }else{
            curr = head;
            for(int i=0;i<size-k-1;++i){
                curr =curr->next;
            }
            ListNode* tmp = curr->next;
            curr->next = nullptr;
            tail->next = head;
            return tmp;
        }
    }
};