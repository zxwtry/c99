//
// Created by zxwtry on 2018/5/22.
//

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

// 快排
void L015_sort(int* arr, int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int partition = L015_partition(arr, startIndex, endIndex);
        L015_sort(arr, startIndex, partition - 1);
        L015_sort(arr, partition + 1, endIndex);
    }
}

int L015_partition(int* arr, int startIndex, int endIndex) {
    int saveValue = arr[startIndex];
    while (startIndex < endIndex) {
        while (startIndex < endIndex && arr[endIndex] >= saveValue) {
            endIndex --;
        }
        arr[startIndex] = arr[endIndex];
        while (startIndex < endIndex && arr[startIndex] <= saveValue) {
            startIndex ++;
        }
        arr[endIndex] = arr[startIndex];
    }
    arr[startIndex] = saveValue;
    return startIndex;
}

// 找到第一个
int L015_binary_find(int* arr, int startIndex, int endIndex, int value) {
    while (startIndex < endIndex) {
        int midIndex = (startIndex + endIndex) / 2;
        int midValue = arr[midIndex];
        if (midValue < value) {
            startIndex = midIndex + 1;
        } else {
             endIndex = midIndex;
        }
    }
    if (startIndex == endIndex && arr[startIndex] == value) {
        return startIndex;
    }
    return -1;
}


void L015_add(int *** ans, int * ansCap, int * ansSize, int v1, int v2, int v3) {
    if (*ansSize == * ansCap) {
        L015_expand(ans, ansCap);
    }
    int * newAdd = (int*) malloc(sizeof(int) * 3);
    newAdd[0] = v1;
    newAdd[1] = v2;
    newAdd[2] = v3;
    (*ans)[*ansSize] = newAdd;
    (*ansSize) ++;
}

void L015_expand(int *** ans, int * ansCap) {
    int newCap = 2 * (*ansCap) + 1;
    int ** newAns = malloc(sizeof(int*) * newCap);
    for (int index = 0; index < *ansCap ; ++index) {
        newAns[index] = (*ans)[index];
    }
    free(*ans);
    *ansCap = newCap;
    *ans = newAns;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// AC 164ms 19.91 %
int** L015_threeSum(int* nums, int numsSize, int* returnSize) {
    int ansCap = 200;
    int ** ans = (int **) malloc(sizeof(int*) * ansCap);
    L015_sort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; ++i) {
        if (i != 0 && nums[i - 1] == nums[i]) {
            continue;
        }
        for (int j = i + 1; j < numsSize; ++j) {
            if (j != i + 1 && nums[j - 1] == nums[j]) {
                continue;
            }
            // 重复的处理
            int target = - nums[i] - nums[j];
            int find = L015_binary_find(nums, j + 1, numsSize - 1, target);
            if (find != -1) {
                L015_add(&ans, &ansCap, returnSize, nums[i], nums[j], nums[find]);
            }
        }
    }
    return ans;
}

void L015_print_arr(int * arr, int startIndex, int endIndex) {
    for (int index = startIndex; index <= endIndex ; ++index) {
        printf("%d ", arr[index]);
    }
    printf("\n");
}


int compare_ints(const void *a, const void *b) {
    return *(int*) a - *(int*) b;
}


// 也很好理解，去重一定要小心
// AC 60ms 97.79 %
int** L015_02_threeSum(int* nums, int numsSize, int* returnSize) {
    int ** ans = NULL;
    if (numsSize < 3) {
        return ans;
    }
    int amount = 0;
    int ansCap = 20;
    *returnSize = 0;
    ans = (int**) malloc(ansCap * sizeof(int*)) ;
    int target, sum, right, left, p, i;
    qsort(nums, numsSize, sizeof(int), compare_ints);
    // 重复处理方法：
    for (p = 0; p < numsSize - 1; ++p) {
        if (p != 0 && nums[p - 1] == nums[p]) {
            continue;
        }
        target = - nums[p];
        left = 1 + p;
        right = numsSize - 1;
        i = p;
        while(left < right) {
            sum = nums[left] + nums[right];
            if (left != p + 1 && nums[left - 1] == nums[left]) {
                left ++;
            } else {
                if (sum < target) {
                    left ++;
                } else if (sum > target) {
                    right --;
                } else {
                    // 这里找到了一个
                    // int *** ans, int * ansCap, int * ansSize, int v1, int v2, int v3
                    L015_add(&ans, &ansCap, returnSize, nums[i], nums[left], nums[right]);
                    left ++;
                    right --;
                }
            }
        }
    }
    return ans;
}

void L015() {
    // [-1,0,1,2,-1,-4]
    int arr [] = {-1,0,1,2,-1,-4, -1, 0, 0};
    int len = 9;
    int ansSize = 0;
    L015_sort(arr, 0, len - 1);
    L015_print_arr(arr, 0, len - 1);
    int ** ans = L015_threeSum(arr, len, &ansSize);
    for (int i = 0; i < ansSize; ++i) {
        L015_print_arr(ans[i], 0, 2);
    }

//    int arr[] = {1, 1, 1, 1, 1};
//    printf("ans is  %d\n", L015_binary_find(arr, 0, 2, 1));
}