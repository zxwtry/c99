/*
    url: leetcode.com/problems/median-of-two-sorted-arrays/
    46ms 38.77%
*/

#include <stdlib.h>
#include <stdio.h>

int L004_0_min(int a, int b) {
    return a < b ? a : b;
}

//binary find  [sorted array of (a1 + a2) k index]
int L004_0_find_kth_from_two_sorted_array(int* a1, int n1, int* a2, int n2, int k) {
    int cut = 0;
    if (n1 > n2) return L004_0_find_kth_from_two_sorted_array(a2, n2, a1, n1, k);
    if (n1 == 0) return *(a2 + k);
    if (k == 0) return L004_0_min(*a1, *a2);
    cut = L004_0_min((k + 1) / 2, n1);
    if (*(a1 + cut - 1) < *(a2 + cut - 1)) {
        return L004_0_find_kth_from_two_sorted_array(a1 + cut, n1 - cut, a2, n2, k - cut);
    } else {
        return L004_0_find_kth_from_two_sorted_array(a1, n1, a2 + cut, n2 - cut, k - cut);
    }
}

//assume all inputs are valid
double L004_0_findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return L004_0_findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    if ((nums1Size + nums2Size) % 2 == 0) {
        return (L004_0_find_kth_from_two_sorted_array(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2) +
                L004_0_find_kth_from_two_sorted_array(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2 - 1)) / 2.0;
    } else {
        return L004_0_find_kth_from_two_sorted_array(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2);
    }
}

int L004() {
    int nums1[4] = {3, 4};
    int nums2[4] = {1, 2, 5, 6};
    //printf("answer is %d\r\n", find_kth_from_two_sorted_array(nums1, 2, nums2, 4, 5));
    printf("answer is %f\r\n", L004_0_findMedianSortedArrays(nums1, 2, nums2, 4));
    return 0;
}