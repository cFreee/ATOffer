#include "solution.h"

//newLen为新的最短长度,初始循环必须为1
void printCombination(char *str, char *outStr, int len, int newLen, int index) {
    for (index; index < len; index++) {
        outStr[newLen - 1] = str[index];
        outStr[newLen] = '\0';
        printf("%s ", outStr);
        if (index < len - 1)
            printCombination(str, outStr, len, newLen + 1, index + 1);
    }
}

void solution::combination() {
    char outStr[6] = {0};
    char *str = "12345";
    printCombination(str, outStr, 5, 1, 0);
}