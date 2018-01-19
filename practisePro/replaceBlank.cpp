#include "solution.h"



void solution::replaceBlank(char string[], int length){
    if(string == NULL && length <= 0){
        return;
    }

    int originLength = 0, numberOfBlank = 0;
    int i = 0;

    while(string[i] != '\0'){
        ++originLength;
        if(string[i] == ' '){
            ++numberOfBlank;
        }
        ++i;
    }

    int newLength = originLength + numberOfBlank * 2;
    if(newLength > length){
        return;
    }

    int indexOfOriginal = originLength, indexOfNew = newLength;
    while(indexOfOriginal > 0 && indexOfNew > indexOfOriginal){
        if(string[indexOfOriginal] == ' '){
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }else{
            string[indexOfNew--] = string[indexOfOriginal];
        }
        --indexOfOriginal;
    }
}

