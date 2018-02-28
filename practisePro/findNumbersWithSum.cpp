#include "solution.h"

bool solution::findNumbersWithSum(int *nums, int len, int *num1, int *num2, int sum) {
    if (nums == NULL || len <= 1)
        return false;

    int start = 0;
    int end = len - 1;
    while (end > start) {
        int curSum = nums[start] + nums[end];
        if (sum == curSum) {
            *num1 = nums[start];
            *num2 = nums[end];
            return true;
        }
        if (curSum > sum) {
            end--;
        } else {
            start++;
        }
    }
    return false;
}