//
// Created by zxwtry on 2018/5/27.
//


#include <stdio.h>
#include <zconf.h>
#include <math.h>

int compare_int(const void * a, const void * b) {
    int a_v = *(int *) a;
    int b_v = *(int *) b;
    if (a_v == b_v) {
        return 0;
    }
    return a_v < b_v ? -1 : 1;
}

// 给定一个ab，判断那个距离t更近
// abs_val就是保存更近的绝对值
// 0 a和b一样近
// -1 a更近
// 1  b更近
int compare_select(int a, int b, int t) {
    if (a > b) {
        return - compare_select(b, a, t);
    } else if (a == b) {
        return 0;
    }
    // 区1  a   区2   b    区3
    // t只能分布在 区1、区2和区3
    if (t <= a) {       // 区1
        return -1;
    }
    if (t >= b) {       // 区3
        return 1;
    }

    // a   t   b 这样的关系，处理溢出情况
    if (t - a < 0) {
        return 1;
    }
    if (b - t < 0) {
        return -1;
    }

    if (t - a == b - t) {
        return 0;
    }
    return t - a < b - t ? -1 : 1;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int ans = 0;
    if (numsSize < 3) {
        return 0;
    }
}

void L016() {
    printf("%d\n", INT_MAX - INT_MIN);
    printf("%d", INT_MIN - INT_MAX);
}