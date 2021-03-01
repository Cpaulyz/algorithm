// https://leetcode-cn.com/problems/linked-list-cycle/
// Created by admin on 2021/3/1.
// 快慢指针，判断环
using namespace std;

#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *quick = head;
        ListNode *slow = head;
        do{
            if(quick==NULL){
                return false;
            }else{
                quick = quick->next;
            }
            if(quick==NULL){
                return false;
            }else{
                quick = quick->next;
            }
            slow = slow->next;
        } while (quick!=slow);
        return true;
    }
};