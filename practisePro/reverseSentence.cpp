#include "solution.h"

void reverse(char *start, char *end) {
    while (start < end) {
        char tmp = *start;
        *start = *end;
        *end = tmp;
    }
}

char *solution::reverseSentence(char *str) {
    if (str == NULL)
        return NULL;

    char *start = str;
    char *end = str + strlen(str) - 1;

    reverse(start, end);

    start = end = str;
    while (*start != '\0') {
        if (*start == ' ') {
            start++;
            end++;
        }

        if (*end == ' ' || *end == '\0') {
            reverse(start, end - 1);   //注意end要减去1
            start = end;
        } else {
            end++;
        }
    }
    return str;
}