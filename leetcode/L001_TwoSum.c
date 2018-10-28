/*
    url: leetcode.com/problems/two-sum/
    twoSum_L001_1: 99ms 59.11%
    twoSum_L001_2:  3ms 94.29%
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


int* twoSum_L001_1(int* nums, int numsSize, int target) {
    int i = 0, j = 0;
    int* ret = (int*)malloc(sizeof(int)*2);
    for (i = 0; i < numsSize; i ++) {
        for (j = i + 1; j < numsSize; j ++) {
            if ((*(nums + i)) + (*(nums + j)) == target) {
                *(ret) = i;
                *(ret + 1) = j;
                return ret;
            }
        }
    }
    return ret;
}

int* twoSum_L001_2(int* nums, int numsSize, int target) {
    int i = 0, j = 0, len = 0;
    int min = (1 << 31) - 1;
    int max = 1 << 31;
    int* map ;
    int* ret = (int*)malloc(sizeof(int) * 2);
    for (i = 0; i < numsSize; i ++) {
        min = min > *(nums + i) ? *(nums + i) : min;
        max = max < *(nums + i) ? *(nums + i) : max;
    }
    min = min < target - max ? target - max : min;
    max = max > target - min ? target - min : max;
    len = max - min + 1;
    map = (int*)malloc(sizeof(int) * len);
    for (i = 0; i < len; i ++)
        *(map + i) = -1;    
    for (i = 0; i < numsSize; i ++) {
        j = *(nums + i) - min;
        if (j > -1 && j < len)
            *(map + j) = i;
    }
    for (i = 0; i < numsSize; i ++) {
        j = target - *(nums + i) - min;
        if (j > -1 && j < len && *(map + j) != -1 && *(map + j) != i) {
            *(ret) = i;
            *(ret + 1) = *(map + j);
            break;
        }
    }
    free(map);
    return ret;
}

// 有趣的解法

typedef struct L001_Object so;

struct L001_Object {
    int val;
    int index;
};

int L001_3_compare(const void *a, const void *b) {
    int av = (*((so **) a))->val;
    int bv = (*((so **) b))->val;
    if (av == bv) {
        return 0;
    }
    return av < bv ? -1 : 1;
}


void L001_3_print(so ** objs, int objsSize) {
    for (int objsIndex = 0; objsIndex < objsSize; objsIndex ++) {
        printf("index:%d value:%d\n", objs[objsIndex]->index, objs[objsIndex]->val);
    }
}


int * L001_3_twosum(int *nums, int numsSize, int target) {
    int i,j,sum;
    int *ans = (int *) malloc(sizeof(int) * 2);
    so ** objs = (so **) malloc(numsSize * sizeof(so *));
    for (i = 0; i < numsSize; i ++) {
        objs[i] = (so *) malloc(sizeof(so));
        objs[i]->val = nums[i];
        objs[i]->index = i;
    }
    qsort(objs, numsSize, sizeof(objs[0]), L001_3_compare);
    i = 0;
    j = numsSize - 1;
    ans[0] = -1;
    ans[1] = -1;
    while (i < j) {
        sum = objs[i]->val + objs[j]->val;
        if (sum == target) {
            ans[0] = min(objs[i]->index, objs[j]->index);
            ans[1] = max(objs[i]->index, objs[j]->index);
            break;
        } else if (sum > target) {
            j --;
        } else {
            i ++;
        }
    }
    return ans;
}


int L001_4_compare(void *a, void *b) {
    int av = * ((int *) a);
    int bv = * ((int *) b);
    if (av == bv) {
        return 0;
    }
    return av < bv ? -1 : 1;
}

void L001_4_print(int *nums, int numsSize) {
    for (int numsIndex = 0; numsIndex < numsSize; numsIndex ++) {
        printf("index:%d   value:%d\n", numsIndex, nums[numsIndex]);
    }
}


void L001_4_qsort_demo() {
    int nums[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int numsSize = 9;
    L001_4_print(nums, numsSize);
    qsort(nums, numsSize, sizeof(nums[0]), L001_4_compare);
    L001_4_print(nums, numsSize);
}


void L001() {
    int num[] = {3,2,4};
    int numSize = 3;
    int target = 5;
    int *ans = L001_3_twosum(&num, numSize, target);
    printf("answer is %d %d\r\n", *(ans), *(ans + 1));
    free(ans);
}
