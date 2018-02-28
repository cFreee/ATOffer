#include "solution.h"

//book's function
void subTreeToList(BinaryTreeNode *root, BinaryTreeNode **lastNode) {
    if (root == NULL) { return; }
    BinaryTreeNode *cur = root;
    if (cur->left != NULL) {
        subTreeToList(root->left, lastNode);
    }
    cur->left = *lastNode;
    if (*lastNode != NULL) {
        (*lastNode)->right = cur;
    }

    *lastNode = cur;

    if (cur->right != NULL) {
        subTreeToList(root->right, lastNode);
    }

}

//my function
BinaryTreeNode *subTreeToList(BinaryTreeNode *root) {
    BinaryTreeNode *maxNode = root;

    if (root->left == NULL && root->right == NULL) {
        return root;
    }

    if (root->left != NULL) {
        BinaryTreeNode *tmp = subTreeToList(root->left);
        root->left = tmp;
        tmp->right = root;
    }

    if (root->right != NULL) {
        BinaryTreeNode *tmp = subTreeToList(root->right);
        maxNode = tmp;
        while (tmp->left != NULL) {
            tmp = tmp->left;
        }
        root->right = tmp;
        tmp->left = root;
    }

    return maxNode;
}

BinaryTreeNode *solution::treeToList(BinaryTreeNode *root) {
    /*
    BinaryTreeNode *lastNode = NULL;
    subTreeToList(root, &lastNode);
    BinaryTreeNode *head = lastNode;
    while (lastNode != NULL && lastNode->left != NULL)
        head = head->left;
    return head;*/

    if (root == NULL) {
        return NULL;
    }

    BinaryTreeNode *leftMax = NULL, *rightMax = NULL;
    if (root->left != NULL) {
        leftMax = subTreeToList(root->left);
        root->left = leftMax;
        leftMax->right = root;
    }

    if (root->right != NULL) {
        rightMax = subTreeToList(root->right);
        while (rightMax->left != NULL) {
            rightMax = rightMax->left;
        }
        root->right = rightMax;
        rightMax->left = root;
    }

    if (leftMax != NULL) {
        while (leftMax->left != NULL) {
            leftMax = leftMax->left;
        }
        return leftMax;
    }
    return root;
}