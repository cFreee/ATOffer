#include "solution.h"

void solution::reorderList(int *number, int n) {
    int start = 0, end = n - 1;

    while(start < end){
        while (start < end && number[start] % 2 == 1)
            start++;

        while (start < end && number[end] % 2 == 0)
            end--;
        if(start < end){
            int tmp = number[start];
            number[start] = number[end];
            number[end] = tmp;
        }
    }
}