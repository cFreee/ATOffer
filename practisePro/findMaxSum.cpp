#include "solution.h"

int solution::findMaxSum(int *nums, int len) {
    bool status = false;
    if (nums == NULL) {
        status = true;
        return 0;
    }
    int sum = nums[0];
    int max = sum;

    for (int i = 1; i < len; i++) {
        sum += nums[i];
        if (sum < nums[i]) {
            sum = nums[i];
        }

        if (sum > max) {
            max = sum;
        }
    }
    return max;
}