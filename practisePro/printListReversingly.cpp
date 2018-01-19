#include "solution.h"


void solution::printListReversingly(ListNode *head){
    if(head == NULL){
        return;
    }
    stack<ListNode*> sta;
    ListNode * cur = head;

    while(cur != NULL){
        sta.push(cur);
        cur = cur->next;
    }

    while(!sta.empty()){
        std::cout << sta.top()->value << std::endl;
        sta.pop();
    }
}

