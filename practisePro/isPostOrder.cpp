#include "solution.h"

bool solution::isPostOrder(int *postOrder, int length) {
    if (postOrder == NULL || length <= 1) {
        return true;
    }

    bool isPost = true;
    int index = 0;
    for (int i = 0; i < length - 1; i++) {
        if (*(postOrder + length - 1) > *(postOrder + i)) {
            index++;
        } else {
            break;
        }
    }

    for (int i = index; i < length - 1; i++) {
        if (*(postOrder + length - 1) > *(postOrder + i)) {
            isPost = false;
            break;
        }
    }
    return isPost && isPostOrder(postOrder, index) && isPostOrder(postOrder + index, length - 1 - index);
}