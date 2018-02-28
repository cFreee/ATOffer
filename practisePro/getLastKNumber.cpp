#include "solution.h"
#include <set>

typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void getLastKNumber(const vector<int> &data, intSet &leastNumbers, int k) {
    leastNumbers.clear();
    if (k < 1 || data.size() < k) {
        return;
    }

    vector<int>::const_iterator it = data.begin();
    for (; it != data.end(); it++) {
        if (leastNumbers.size() < k)
            leastNumbers.insert(*it);
        else if (*it < *(leastNumbers.begin())) {
            leastNumbers.erase(leastNumbers.begin());
            leastNumbers.insert(*it);
        }
    }
}

void swap(int *num1, int *num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int partition(int *data, int length, int start, int end) {
    if (data == NULL || length <= 0 || start < 0 || end >= length) {
        logic_error ex("input invalid.");
        throw exception(ex);
    }

    //notice
    int index = start;
    while (start < end) {
        while (end > start && data[end] >= data[index])
            end--;
        swap(&data[index], &data[end]);
        index = end;
        while (end > start && data[start] <= data[index])
            start++;
        swap(&data[index], &data[start]);
        index = start;
    }
    return index;
}

void solution::getLastKNumber(int *nums, int *outNums, int len, int k) {
    if (nums == NULL || outNums == NULL || k > len || len <= 0 || k <= 0) {
        return;
    }

    int start = 0;
    int end = len - 1;

    int index = partition(nums, len, start, end);

    while (index != k - 1) {
        if (index > k - 1) {
            end = index - 1;
            index = partition(nums, len, start, end);
        } else {
            start = index + 1;
            index = partition(nums, len, start, end);
        }
    }

    for (int i = 0; i < k; i++)
        outNums[i] = nums[i];
}