// https://leetcode-cn.com/problems/reverse-linked-list-ii/
// Created by admin on 2021/3/13.
//
using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode* hd = head;
        ListNode* pre = head;
        for (int i = 2; i < left; ++i) {
            pre = pre->next;
        }
        if(left>1){
            hd = pre->next;
        }
        ListNode* cur = hd;
        ListNode* tail = hd->next;
        for (int i = 0; i < right-left  ; ++i) {
            ListNode* tmp = tail;
            cur->next = tail->next;
            tail->next = hd;
            hd = tail;
            tail = cur->next;
        }
        if(left==1){
            return hd;
        }else{
            pre->next = hd;
            return head;
        }
    }
};

int main(){
    Solution s;
    ListNode* n = new ListNode(5);
    s.reverseBetween(n,1,1);
}