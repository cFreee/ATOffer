#include "solution.h"

ListNode *solution::mergeList(ListNode *l1, ListNode *l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    ListNode *head = NULL, *cur;

    if (l1->value < l2->value) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }

    cur = head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->value <= l2->value) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        } else {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
    }

    if(l1 != NULL)
        cur->next = l1;
    if(l2 != NULL)
        cur->next = l2;
    return head;
}