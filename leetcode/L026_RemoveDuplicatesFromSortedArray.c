/*
    url: leetcode.com/problems/remove-duplicates-from-sorted-array/
    15ms 35.07%
*/

#include <stdio.h>
#include <stdlib.h>

int L026_removeDuplicates(int* nums, int numsSize) {
    int i = 0, j = 0, count = 1;
    if (numsSize < 2) return numsSize;
    for (j = 1, i = 1; j < numsSize; j ++) {
        if (*(nums + j - 1) != *(nums + j)) {
            count ++;
            *(nums + (i ++)) = *(nums + j);
        }
    }
    return count;
}

void L026_print_array(int * nums, int numsSize) {
    int i = 0;
    for (i = 0; i < numsSize; i ++)
        printf("%d ", *(nums + i));
    printf("\r\n");
}

int L026() {
    int nums [] = {1, 1, 2, 2};
    int numsSize = 4;
    L026_print_array(nums, L026_removeDuplicates(nums, numsSize));
}