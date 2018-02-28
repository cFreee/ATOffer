#include "solution.h"

ListNode *solution::reverseList(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    ListNode* pre = head;
    ListNode* cur = head->next;
    head->next =NULL;

    while (cur != NULL){
        ListNode* tmp = cur;
        cur = cur->next;
        tmp->next = pre;
        pre = tmp;
    }

    return pre;
}