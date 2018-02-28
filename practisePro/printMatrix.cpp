#include "solution.h"

void solution::printMatrix(int **matrix, int row, int col) {
    if (matrix == NULL) {
        return;
    }
    int count = 0;
    int max = col < row ? col : row;
    bool hasSingleLine = max % 2 == 1 ? true : false;

    for (; count < max / 2; count++) {
        for (int i = count; i < col - count - 1; i++)
            cout << matrix[count][i] << " ";
        for (int i = count; i < row - count - 1; i++)
            cout << matrix[i][col - 1 - count] << " ";
        for (int i = count; i < col - count - 1; i++)
            cout << matrix[row - 1 - count][col - 1 - i] << " ";
        for (int i = count; i < row - count - 1; i++)
            cout << matrix[row - 1 - i][count] << " ";
    }

    if (hasSingleLine) {
        if (col > row) {
            for (int i = max / 2; i < col - max / 2; i++)
                cout << matrix[max / 2][i] << " ";
        } else {
            for (int i = max / 2; i < row - max / 2; i++)
                cout << matrix[i][max / 2] << " ";
        }
    }
}