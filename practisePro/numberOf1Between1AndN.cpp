#include "solution.h"

int powOf10(int len) {
    int num = 1;
    while (len > 0) {
        num *= 10;
        len--;
    }
    return num;
}

int numberOf1(const char *str) {
    int length = strlen(str);
    int num = *str - '0';
    int count = 0;

    //长度为1时跳出，并根据数字来决定返回1还是0
    if (length == 1 && num == 0) {
        return 0;
    }
    if (length == 1 && num > 0) {
        return 1;
    }

    //计算最高位为1时的包含1的个数
    if (num > 1) {
        count += powOf10(length - 1);
    } else if (num == 1) {
        count += atoi(str + 1) + 1;
    }

    count += num * (length - 1) * powOf10(length - 2);

    return count + numberOf1(str + 1);
}

int solution::numberOf1Between1AndN(int n) {
    if (n <= 0) {
        return 0;
    }

    char nums[50] = {0};
    sprintf(nums, "%d", n);
    return numberOf1(nums);
}
