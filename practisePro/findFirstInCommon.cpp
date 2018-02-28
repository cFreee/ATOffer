#include "solution.h"

int calLen(ListNode *head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

ListNode *newHead(ListNode *head, int k) {
    while (k > 0) {
        head = head->next;
        k--;
    }
    return head;
}

ListNode *solution::findFirstInCommon(ListNode *head1, ListNode *head2) {
    if (head1 == NULL || head2 == NULL)
        return NULL;
    int len1 = calLen(head1), len2 = calLen(head2);
    ListNode *tmp1 = head1, *tmp2 = head2;

    if (len1 - len2 > 0) {
        tmp1 = newHead(head1, len1 - len2);
    } else {
        tmp2 = newHead(head2, len2 - len1);
    }

    while (tmp1 != NULL && tmp1 != tmp2) {
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    return tmp1;
}