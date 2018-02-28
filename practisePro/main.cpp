#include <iostream>
#include"solution.h"

using namespace std;

void printList(ListNode *head) {
    ListNode *cur = head;
    while (cur != NULL) {
        cout << cur->value << "\n";
        cur = cur->next;
    }
    cout << "\n";
}

ListNode *makeList(int n) {
    ListNode *head = NULL;
    ListNode *cur;
    int count = 0;
    while (n > count) {
        ListNode *tmp = new ListNode(count);
        if (head == NULL) {
            head = tmp;
            cur = head;
        } else {
            cur->next = tmp;
            cur = tmp;
        }
        ++count;
    }
    return head;
}

void p(const char *str) {
    cout << strlen(str);
}

int main() {
    solution s;
    BinaryTreeNode *head = new BinaryTreeNode(10);
    head->left = new BinaryTreeNode(5);
    head->right = new BinaryTreeNode(12);
    head->right->left = new BinaryTreeNode(11);
    head->right->right = new BinaryTreeNode(13);
    head->right->right->right = new BinaryTreeNode(15);
    head->left->left = new BinaryTreeNode(4);
    head->left->right = new BinaryTreeNode(7);
    BinaryTreeNode *tmp = s.treeToList(head);
    int nums[6] = {7, 5, 6, 4, 3,2};
    cout<<s.inversePairs(nums, 6)<<endl;
    for(int num:nums){
        cout<<num;
    }

    return 0;
}

