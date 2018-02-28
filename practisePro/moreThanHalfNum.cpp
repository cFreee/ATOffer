#include "solution.h"
#include <map>

int moreThanHalfNumWithMap(int *nums, int len) {
    map<int, int> map1;
    map<int, int>::iterator it;
    for (int i = 0; i < len; i++) {
        it = map1.find(nums[i]);
        if (it != map1.end()) {
            int tmp = it->second + 1;
            map1.erase(it);
            map1.insert(pair<int, int>(nums[i], tmp));
        } else {
            map1.insert(pair<int, int>(nums[i], 1));
        }
    }

    it = map1.begin();

    int max = it->second;
    while (it != map1.end()) {
        if (max < it->second) {
            max = it->second;
        }
        it++;
    }
    return max;
}

//注意，本部分未按照书中编写,缺漏部分为：检查数组是否规范， 得到结果是否为超过一半的数字
int solution::moreThanHalfNum(int *nums, int len) {
    if (nums == NULL) {
        return 0;
    }

    int result = nums[0], time = 1;

    for (int i = 1; i < len; i++) {
        if (time == 0) {
            result = nums[i];
            time = 1;
        } else if (nums[i] == result) {
            time++;
        } else {
            time--;
        }
    }
    return result;
}