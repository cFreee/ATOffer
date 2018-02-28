#include "solution.h"

int getFirstK(int *nums, int start, int end, int k) {
    if (start > end)
        return -1;

    int mid = (start + end) / 2;
    int key = nums[mid];

    if (key == k) {
        if ((mid > 0 && nums[mid - 1] != k) || mid == 0)
            return mid;
        else
            end = mid - 1;
    } else if (key > k) {
        end = mid - 1;
    } else {
        start = mid + 1;
    }

    return getFirstK(nums, start, end, k);
}

int getLastK(int *nums, int start, int end, int len, int k) {
    if (start > end)
        return -1;

    int mid = (start + end) / 2;
    int key = nums[mid];

    if (key == k) {
        if ((mid < len - 1 && nums[mid + 1] != k) || mid == len - 1) {
            return mid;
        } else {
            return mid + 1;
        }
    } else if (mid < k) {
        start = mid + 1;
    } else {
        end = mid - 1;
    }

    return getLastK(nums, start, end, len, k);
}

int solution::getNumberOfK(int *nums, int len, int k) {
    if (nums == NULL || len == 0) {
        return 0;
    }

    int first = getFirstK(nums, 0, len - 1, k);
    int last = getLastK(nums, 0, len - 1, len, k);

    if (first > -1 && last > -1)
        return last - first + 1;
    else
        return 0;
}