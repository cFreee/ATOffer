#include "solution.h"

const int maxLen = 10;
char *combine1 = new char[maxLen * 2 + 1];
char *combine2 = new char[maxLen * 2 + 1];

int compare(const void *strNum1, const void *strNum2) {
    strcpy(combine1, *(const char **) strNum1);
    strcat(combine1, *(const char **) strNum2);

    strcpy(combine2, *(const char **) strNum2);
    strcat(combine2, *(const char **) strNum1);

    return strcmp(combine1, combine2);
}

void solution::printMinNumber(int *nums, int len) {
    if (nums == NULL || len <= 0)
        return;

    char **strNums = new char *[len];
    for (int i = 0; i < len; i++) {
        strNums[i] = new char[maxLen + 1];
        sprintf(strNums[i], "%d", nums[i]);
    }

    qsort(strNums, len, sizeof(char *), compare);

    for (int i = 0; i < len; i++) {
        cout << strNums[i];
    }
    cout << endl;

    for (int i = 0; i < len; i++) {
        delete[] strNums[i];
    }
    delete[] strNums;
}
