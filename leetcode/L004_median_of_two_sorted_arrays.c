//
// Created by zxwtry on 2018/5/15.
//

#include <stdio.h>


// k start with 0
int L004_findKthInTwoArray(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    int compareIndex = 0;
    if (nums1Size > nums2Size) {
        return L004_findKthInTwoArray(nums2, nums2Size, nums1, nums1Size, k);
    }
    if (nums1Size == 0) {
        return nums2[k];
    }
    if (k == 0) {
        return nums1[0] < nums2[0] ? nums1[0] : nums2[0];
    }
    compareIndex = (k + 1) / 2 - 1;
    if (compareIndex >= nums1Size) {
        compareIndex = nums1Size - 1;
    }
    if (nums1[compareIndex] < nums2[compareIndex]) {
        return L004_findKthInTwoArray(nums1 + compareIndex + 1, nums1Size - compareIndex - 1,
                                 nums2, nums2Size, k - compareIndex - 1);
    } else {
        return L004_findKthInTwoArray(nums1, nums1Size, nums2 + compareIndex + 1,
                                 nums2Size - compareIndex - 1, k - compareIndex - 1);
    }
}

double L004_findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size + nums2Size;
    int mid = (size - 1) / 2;
    if (size % 2 == 0) {
        double sum = 0;
        sum += L004_findKthInTwoArray(nums1, nums1Size, nums2, nums2Size, mid);
        sum += L004_findKthInTwoArray(nums1, nums1Size, nums2, nums2Size, mid + 1);
        return sum / 2;
    } else {
        return (double) L004_findKthInTwoArray(nums1, nums1Size, nums2, nums2Size, mid);
    }
}

void L004() {
    int nums1[] = {1, 2};
    int nums1Size = 2;

    int nums2[] = {1 , 2 , 3};
    int nums2Size = 3;

//    for (int i = 0; i < nums1Size + nums2Size; ++i) {
//        printf("%d : %d\n", i, findKthInTwoArray(nums1, nums1Size, nums2, nums2Size, i));
//    }

    printf("ans is %f\n", L004_findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
}