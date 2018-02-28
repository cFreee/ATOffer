#include "solution.h"

void solution::printBTreeFromTopToBottom(BinaryTreeNode *head) {
    queue<BinaryTreeNode *> q;

    if (head == NULL) {
        return;
    }

    q.push(head);

    while (q.size() == 0) {
        BinaryTreeNode *tmpNode = q.front();
        cout << tmpNode->value << endl;
        if (tmpNode->left != NULL)
            q.push(tmpNode->left);
        if (tmpNode->right != NULL)
            q.push(tmpNode->right);
        q.pop();
    }
}

