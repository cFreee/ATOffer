#include "solution.h"

void solution::deleteNode(ListNode *head, ListNode* deleteNode) {
    if(head == NULL || deleteNode == NULL){
        return;
    }
    if(deleteNode->next == NULL){
        while(head!=NULL && head->next != deleteNode){
            head = head->next;
        }
        head->next = NULL;
        delete deleteNode;
    }else{
        ListNode* tmp = deleteNode->next;
        deleteNode->value = tmp->value;
        deleteNode->next = tmp->next;
        delete tmp;
    }
}