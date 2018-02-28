#include "solution.h"

unsigned int findFirstBitIs1(int num) {
    int indexBit = 0;

    while ((num & 1) == 0 && indexBit < 8 * sizeof(int)) {
        num = num >> 1;
        indexBit++;
    }
    return indexBit;
}


bool isBit1(int num, unsigned int indexBit) {
    num = num >> indexBit;
    return (num & 1);
}

void solution::findNumAppendOnce(int *nums, int len, int *num1, int *num2) {
    int num = 0;

    for (int i = 0; i < len; i++) {
        num ^= nums[i];
    }

    unsigned int indexOf1 = findFirstBitIs1(num);

    *num1 = *num2 = 0;

    for (int i = 0; i < len; i++) {
        if (isBit1(nums[i], indexOf1))
            *num1 ^= nums[i];
        else
            *num2 ^= nums[i];
    }
}