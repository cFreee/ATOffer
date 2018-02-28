#include"solution.h"

int minOrder(int *numbers, int index1, int index2){
    int res = numbers[index1];
    for(int i = index1 + 1; i <=index2; i++){
        if(res > numbers[i]){
            res = numbers[i];
        }
    }
    return res;
}

int solution::minNum(int* number, int length){
    if(number == NULL || length <= 0){
        logic_error ex("invlid input.");
        throw exception(ex);
    }

    int index1 = 0, index2 = length - 1;

    while(index1 + 1 < index2){
        int mid = (index1 + index2) / 2;
        if(number[index1] == number[mid] && number[index2] == number[mid]){
            return minOrder(number, index1, index2);
        }
        else if(number[mid] >= number[index1]){
            index1 = mid;
        }else{
            index2 = mid;
        }
    }
    index2 = number[index1] > number[index2]?index2:index1;
    return number[index2];
}

/*****************************************************
 * 书上的解法
 *
int solution::minNum(int *numbers, int length){
    if(numbers == NULL || length <= 0){
        logic_error ex("invlid input.");
        throw exception(ex);
    }

    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;

    while( numbers[index1] >= numbers[index2]){
        if(index2 - 1 == index1){
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2) / 2;
        if(numbers[index1] == numbers[mid] && numbers[index2] == numbers[mid]){
            return minOrder(numbers, index1, index2);
        }
        if(numbers[indexMid] >= numbers[index1]){
            index1 = indexMid;
        }else if(numbers[indexMid] <= numbers[index2]){
            index2 = indexMid;
        }
    }
    return numbers[indexMid];
}
*******************************************************/
