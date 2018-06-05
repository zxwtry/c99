//
// Created by zxwtry on 2018/6/5.
//


#include <stdio.h>

void L031_swap(int * a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void L031_reverse(int * arr, int a, int b) {
    while (a < b) {
        L031_swap(&arr[a], &arr[b]);
        a ++;
        b --;
    }
}


//[i, j]
int L031_search_little_bigger(int * n, int i, int j, int v) {
    int m;
    while (i < j) {
        m = i + (j - i + 1) / 2;
        if (n[m] > v) {
            i = m;
        } else {
            j = m - 1;
        }
    }
    return i;
}


void L031_nextPermutation(int* nums, int numsSize) {
    int i, j;
    for (i = numsSize - 2; i > -1 && nums[i] >= nums[i + 1]; --i) {}
    if (i == -1){
        L031_reverse(nums, 0, numsSize - 1);
    } else {
        L031_swap(nums + i, nums + L031_search_little_bigger(nums, i + 1, numsSize - 1, nums[i]));
        L031_reverse(nums, i + 1, numsSize - 1);
    }
}

void L031_print(int * arr, int size) {
    int index = 0;
    while (index < size) {
        printf("index:%d\t\t%d\n", index, arr[index]);
        index ++;
    }
}


void L031() {
    int nums [] = {1, 2, 3, 3, 2, 1};
    int numsSize = 6;
    L031_nextPermutation(nums, numsSize);
    L031_print(nums, numsSize);
}