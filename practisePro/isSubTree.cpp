#include "solution.h"

bool isEqual(BinaryTreeNode *t1, BinaryTreeNode *t2) {
    if (t2 == NULL)
        return true;
    if (t1 == NULL)
        return false;
    if (t1->value != t2->value) {
        return false;
    }
    return isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right);
}

bool solution::isSubTree(BinaryTreeNode *t1, BinaryTreeNode *t2) {
    if (t2 == NULL) {
        return true;
    }
    if (t1 == NULL) {
        return false;
    }

    if (isEqual(t1, t2)) {
        return true;
    } else {
        bool left = false, right = false;
        if(t1->left != NULL){
            left = isSubTree(t1->left, t2);
        }
        if(t1->right != NULL){
            right = isSubTree(t1->right, t2);
        }
        return left || right;
    }
}

