#include "solution.h"

ListNode* solution::theLastKthNode(ListNode *head, int k ) {
    if(head == NULL && k <= 0){
        return NULL;
    }

    ListNode* KthNode = head;
    while (k > 0){
        if(KthNode != NULL)
            KthNode = KthNode->next;
        else{
            logic_error ex("invalid k.");
            throw exception(ex);
        }
        k--;
    }

    while (KthNode != NULL){
        KthNode = KthNode->next;
        head = head->next;
    }
    return head;
}