/*
    url: leetcode.com/problems/maximum-product-subarray
    AC 3ms 28.57%
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int L152_maxProduct(int* nums, int numsSize) {
    int * pm = (int *) malloc(sizeof(int) * (numsSize + 1));
    int * nm = (int *) malloc(sizeof(int) * (numsSize + 1));
    int index = 0, maxValue = 0, minValue = 0, answer = INT_MIN;
    pm[0] = 1;
    nm[0] = 1;
    for (index = 0; index < numsSize; index ++) {
        maxValue = nums[index] * pm[index];
        minValue = nums[index] * nm[index];
        pm[index + 1] = max(maxValue, minValue);
        nm[index + 1] = min(maxValue, minValue);
        pm[index + 1] = max(pm[index + 1], nums[index]);
        nm[index + 1] = min(nm[index + 1], nums[index]);
        answer = max(answer, pm[index + 1]);
    }
    free(pm);
    free(nm);
    return answer == INT_MIN ? 0 : answer;
}

int L152(void) {
    int nums[] = {2,3,-1,-2,-4};
    int numsSize = 5;
    printf("answer is %d\n", L152_maxProduct(nums, numsSize));
    return 0;
}