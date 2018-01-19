#include "solution.h"

bool solution::searchBinArr(int* martix, int rows, int columns, int number){
    bool found = false;
    if(martix != NULL && rows > 0 && columns > 0){
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >=0){
            if(martix[rows * columns + column] == number){
                found = true;
                break;
            }
            else if(martix[rows * columns + column] > number){
                --column;
            }else{
                ++row;
            }
        }
    }
    return found;
}

