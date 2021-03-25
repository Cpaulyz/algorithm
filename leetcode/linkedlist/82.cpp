// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
// Created by admin on 2021/3/25.
// 判断nullptr比较多

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head== nullptr){
            return nullptr;
        }
        int tmp = 0;
        if(head->next!= nullptr&&head->val==head->next->val){
            tmp = head->val;
            head = head->next;
            while (head!= nullptr&&head->val==tmp){
                head = head->next;
            }
        }
        ListNode *curr = head;
        while (curr->next!= nullptr&&curr->next->next != nullptr) {
            if (curr->next->val==curr->next->val){
                tmp = curr->next->val;
                curr->next = curr->next->next;
            }else if(curr->next->val==tmp){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};