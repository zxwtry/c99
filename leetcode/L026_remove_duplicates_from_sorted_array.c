//
// Created by zxwtry on 2018/6/2.
//

#include <stdio.h>

void L026_print(int * array, int size) {
    int index = 0;
    for (index = 0; index < size; ++index) {
        printf("%d\t\t%d\n", index, array[index]);
    }
}

// AC 12ms 71.16 %
int L026_removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2) {
        return numsSize;
    }
    int preValue = nums[0];
    int writeIndex = 1;
    int index = 0;
    for (index = 1; index < numsSize; ++index) {
        if (nums[index] != preValue) {
            nums[writeIndex ++] = nums[index];
        }
        preValue = nums[index];
    }
    return writeIndex;
}


void L026() {
    int array[] = {1, 1, 2, 2, 3, 4, 5, 6};
    int size = 6;
    int returnSize = L026_removeDuplicates(array, size);
    L026_print(array, returnSize);
}