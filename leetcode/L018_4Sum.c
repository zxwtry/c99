//
// Created by zxwtry on 2018/5/28.
//




#include <stdlib.h>
#include <stdio.h>


void L018_add(int *** ans, int * cap, int * size, int a, int b, int c, int d) {
    int ** tmp = NULL;
    int i = 0;
    int * add = (int *) malloc(sizeof(int) * 4);
    add[0] = a;
    add[1] = b;
    add[2] = c;
    add[3] = d;
    if (*cap == *size) {
        *cap = (*cap) * 2 + 1;
        tmp = (int **) malloc(sizeof(int *) * (*cap));
        for (i = 0; i < *size; ++i) {
            tmp[i] = (*ans)[i];
        }
        free(*ans);
        *ans = tmp;
    }
    (*ans)[(*size) ++] = add;
}

int L018_compare_int(void * a, void * b) {
    int av = *((int *)a);
    int bv = *((int *)b);
    if (av ==  bv) return 0;
    return av < bv ? -1 : 1;
}


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// AC 24ms 51.47 %
// 添加二循环内判断之后
// AC 8ms 100 %
int** L018_fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, s, t;
    int cap = 1000;
    int ** ans = (int **) malloc(sizeof(int *) * cap);
    int diff = 0;
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), L018_compare_int);
    for (i = 0; i < numsSize - 3; ++i) {
        if (i != 0 && nums[i - 1] == nums[i]) {
            continue;
        }
        for (j = i + 1; j < numsSize - 2; ++j) {
            if (j != i + 1 && nums[j - 1] == nums[j]) {
                continue;
            }
            s = j + 1;
            t = numsSize - 1;
            if (nums[i] + nums[j] + nums[s] + nums[s + 1] > target) {
                continue;
            }
            if (nums[i] + nums[j] + nums[t - 1] + nums[t] < target) {
                continue;
            }
            while (s < t) {
                if (s != j + 1 && nums[s - 1] == nums[s]) {
                    s ++;
                } else {
                    diff = nums[i] + nums[j] + nums[s] + nums[t] - target;
                    if (diff == 0) {
                        L018_add(&ans, &cap, returnSize, nums[i], nums[j], nums[s], nums[t]);
                        s ++;
                        t --;
                    } else if (diff < 0) {
                        s ++;
                    } else {
                        t --;
                    }
                }
            }
        }
    }
    return ans;
}

void L018() {
    int nums[] = {1, 0, -1, 0, -2, 2, -2, -2, -2, -2, -2};
    int numsSize = 11;
    int target = 0;
    int returnSize = 0;
    int i = 0;
    int j = 0;
    int ** ans = L018_fourSum(nums, numsSize, target, &returnSize);
    printf("size is %d\n", returnSize);
    for (i = 0; i < returnSize; ++i) {
        for (j = 0; j < 4; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}