#include "solution.h"

void printNumber(char* str, int n){
    for(int i = 0; i < n - 1; i++){
        if(*str == '0'){
            str++;
        }else{
            break;
        }
    }
    printf("%s\n", str);
}

void printOnRecursive(int index, char *num, int n){
    if(index == n){
        printNumber(num, n);
        return;
    }
    for(int i = 0; i < 10; i++){
        num[index] = i + '0';
        printOnRecursive(index + 1, num, n);
    }
}

void solution::printNDigits(int n) {
    char *num = new char[n];
    printOnRecursive(0, num, n);
}