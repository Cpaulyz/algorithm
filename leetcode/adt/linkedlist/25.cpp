// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
// Created by admin on 2021/2/20.
//

using namespace std;

#include <vector>
#include <string>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL){
            return NULL;
        }
        // 先检查是否>=k
        ListNode* tmp = head;
        int len= 0;
        while (tmp!=NULL){
            len++;
            tmp = tmp->next;
            if(len>=k){
                break;
            }
        }
        if(len<k){
            return head;
        }
        // 翻转k个，后面的递归做
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* tail = head;
        for (int i = 0; i < k; ++i) {
            curr = head;
            head = head->next;
            curr->next = pre;
            pre = curr;
        }
        tail->next = reverseKGroup(head,k);
        return curr;
    }
};