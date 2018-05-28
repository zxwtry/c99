//
// Created by zxwtry on 2018/5/27.
//


#include <stdio.h>
#include <zconf.h>
#include <math.h>
#include <stdlib.h>

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

void L016_solve_ans_compare(int * ans, int new_ans, int target) {
    if (compare_select(*ans, new_ans, target) > 0) {
        * ans = new_ans;
    }
}

int L016_binary_find_near(int * nums, int startIndex, int endIndex, int target) {
    int midIndex = 0;
    int midValue = 0;
    while (startIndex + 1 < endIndex) {
        midIndex = startIndex + (endIndex - startIndex) / 2;
        midValue = nums[midIndex];
        if (midValue > target) {
            endIndex = midIndex;
        } else if (midValue < target) {
            startIndex = midIndex;
        } else {
            return midIndex;
        }
    }
    if (compare_select(nums[startIndex], nums[endIndex], target) < 0) {
        return startIndex;
    } else {
        return endIndex;
    }
}

// AC 16ms 33.06 %
int L016_threeSumClosest(int* nums, int numsSize, int target) {
    int ans = 0;
    int i = 0, j = 0, k = 0, a = 0;
    long long sum = 0;
    if (numsSize < 3) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), compare_int);
    ans = nums[0] + nums[1] + nums[2];
    for (i = 0; i < numsSize - 2; ++i) {
        if (i != 0 && nums[i - 1] == nums[i]) {
            continue;
        }
        for (j = i + 1; j < numsSize - 1; ++j) {
            if (j != i + 1 && nums[j - 1] == nums[j]) {
                continue;
            }
            sum = target;
            sum -=  nums[i];
            sum -=  nums[j];
            k = L016_binary_find_near(nums, j + 1, numsSize - 1, sum);
            L016_solve_ans_compare(&ans, nums[i] + nums[j] + nums[k], target);
        }
    }
    return ans;
}

// 查找 N ^ 2 一样可以实现
int L016_02_threeSumClosest(int* nums, int numsSize, int target) {
    int i, j, k, a, s;
    if (numsSize < 3) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), compare_int);
    a = nums[0] + nums[1] + nums[2];
    for (i = 0; i < numsSize - 2; ++i) {
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            s = nums[i] + nums[j] + nums[k];
            if (s < target) {
                j ++;
            } else if (s > target) {
                k --;
            } else {
                return s;
            }
            L016_solve_ans_compare(&a, s, target);
        }
    }
    return a;
}


void L016() {
    int nums[] = {1,1,-1,-1,3};
    int numsSize = 5;
    int target = 1;
    printf("ans is %d\n", L016_02_threeSumClosest(nums, numsSize, target));
}