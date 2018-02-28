#include "solution.h"

int calDeep(BinaryTreeNode *head) {
    if (head->left == NULL && head->right == NULL) {
        return 1;
    }

    int left = 0, right = 0;
    if (head->left != NULL)
        left = calDeep(head->left);
    if (head->right != NULL)
        right = calDeep(head->right);

    return left > right ? left + 1 : right + 1;
}

int solution::deepOfTree(BinaryTreeNode *head) {
    if (head == NULL)
        return 0;
    return calDeep(head);
}