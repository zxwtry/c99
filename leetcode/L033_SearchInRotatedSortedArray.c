/*
    url: leetcode.com/problems/search-in-rotated-sorted-array/
*/

#include <stdio.h>
#include <stdlib.h>

//[i, j)
int L033_s(int* n, int i, int j, int t) {
    int m = 0;
    j --;
    if (n[i] == t) return i;
    else if (j > i && n[j] == t) return j;
    while (i <= j) {
        m = i + (j - i) / 2;
        if (n[m] == t) {
            return m;
        } else if (n[m] > t) {
            j = m - 1;
        } else {
            i = m + 1;
        }
    }
    return -1;
}

//[i, j)
int L033_search(int* n, int i, int j, int t) {
    int m = 0, a = -1;
    j --;
    if (i > j) return -1;
    if (n[j] < n[i]) {
        m = i + (j - i) / 2;
        if (n[m] == t) return m;
        if (n[m] > n[i]) {
            a = L033_s(n, i, m, t);
            if (a != -1) return a;
            a = L033_search(n, m + 1, j, t);
        } else {
            a = L033_s(n, m + 1, j, t);
            if (a != -1) return a;
            a = L033_search(n, i, m, t);
        }
        return a;
    } else {
        return L033_s(n, i, j + 1, t);
    }
}

int L033_search_entry(int* nums, int numsSize, int target) {
    if (numsSize < 1) return -1;
    else if (nums[0] == target) return 0;
    else if (nums[numsSize - 1] == target) return numsSize - 1;
    return L033_search(nums, 0, numsSize, target);
}

int L033() {
    int n [] = {3, 1};
    int ns = 2;
    int t = 2;
    //for (t = -20; t < 21; t ++)
        printf("t is %d answer is %d\r\n", t, L033_search_entry(n, ns, t));
}