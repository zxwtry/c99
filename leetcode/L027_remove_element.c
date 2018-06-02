//
// Created by zxwtry on 2018/6/2.
//

// AC 4ms  94.29 %
int L027_removeElement(int* nums, int numsSize, int val) {
    int writeIndex = 0;
    int index = 0;
    for (index = 0; index < numsSize; ++index) {
        if (nums[index] != val) {
            nums[writeIndex ++] = nums[index];
        }
    }
    return writeIndex;
}