#include "solution.h"

int Min(int a, int b, int c) {
    int min = a < b ? a : b;
    return min < c ? min : c;
}

int solution::getUglyNumber(int index) {
    if (index <= 0)
        return 0;

    int curIndex = 1;
    int *uglyNumbers = new int[index];
    uglyNumbers[0] = 1;

    int *multiply2 = uglyNumbers;
    int *multiply3 = uglyNumbers;
    int *multiply5 = uglyNumbers;

    while (curIndex < index) {
        int min = Min(*multiply2 * 2, *multiply3 * 3, *multiply5 * 5);
        uglyNumbers[curIndex] = min;

        while (*multiply2 * 2 <= uglyNumbers[curIndex])
            multiply2++;
        while (*multiply3 * 3 <= uglyNumbers[curIndex])
            multiply3++;
        while (*multiply5 * 5 <= uglyNumbers[curIndex])
            multiply5++;
        curIndex++;
    }

    int uglyNumber = uglyNumbers[index - 1];
    delete[] uglyNumbers;
    return uglyNumber;
}