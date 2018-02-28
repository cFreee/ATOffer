#include "solution.h"

ComplexListNode *solution::clone(ComplexListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    ComplexListNode *cur = head;

    //clone
    while (cur != NULL) {
        ComplexListNode *tmp = new ComplexListNode(cur->value);
        tmp->next = cur->next;
        cur->next = tmp;
        cur = tmp->next;
    }

    //sibling
    cur = head;
    while (cur != NULL) {
        ComplexListNode *tmp = cur->next;
        if (cur->sibling != NULL)
            tmp->sibling = cur->sibling->next;
        cur = tmp->next;
    }

    //divide
    cur = head;
    ComplexListNode *cloneHead = cur->next;
    while (cur != NULL) {
        ComplexListNode *tmp = cur->next;
        cur->next = tmp->next;
        cur = cur->next;
        if (cur != NULL) {
            tmp->next = cur->next;
        }
    }
    return cloneHead;
}