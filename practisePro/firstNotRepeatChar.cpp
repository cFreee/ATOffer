#include "solution.h"

char solution::firstNotRepeatChar(char *str) {
    if (str == NULL)
        return '\0';
    const int tableSize = 256;
    unsigned int hashTable[tableSize];

    for (unsigned int i = 0; i < tableSize; i++)
        hashTable[i] = 0;

    char *cur = str;

    while (*cur != '\0') {
        hashTable[*cur]++;
        cur++;
    }

    cur = str;

    while (*cur != '\0') {
        if (hashTable[*cur] == 1)
            return *cur;
        cur++;
    }
    return '\0';
}