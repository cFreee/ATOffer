#include "solution.h"

bool solution::isValidOrder(int *push, int *pop, int length) {
    bool gStatus = false;

    if (push == NULL || length <= 0 || pop == NULL) {
        gStatus = true;
        return false;
    }

    stack<int> s1;
    int index1 = 0, index2 = 0;

    while (index1 < length) {
        if (s1.size() > 0 && s1.top() == *pop) {
            s1.pop();

        } else {
            if (length <= index2) {
                return false;
            }
            while (index2 < length && *push != *pop) {
                s1.push(*push);
                push++;
                index2++;
            }
            if (*push != *pop) {
                return false;
            } else {
                index2++;
                push++;
            }
        }
        pop++;
        index1++;
    }

    return true;
}



