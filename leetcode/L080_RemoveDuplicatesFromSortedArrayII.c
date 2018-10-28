#include <stdio.h>

/*
    url: leetcode.com/problems/remove-duplicates-from-sorted-array-ii
    AC 6ms 19.72%
*/

int L080_removeDuplicates(int* n, int nn) {
    int bi = 0, fi = 0, cnt = 0;
    while (fi < nn) {
        if (fi != 0 && n[fi] == n[fi-1]) {
            cnt ++;
            if (cnt == 1) {
                n[bi ++] = n[fi];
            }
        } else {
            cnt = 0;
            n[bi ++] = n[fi];
        }
        fi ++;
    }
    return bi;
}

int L080() {
    int n[] = {1, 1};
    int nn = 2;
    printf("answer is %d\r\n", L080_removeDuplicates(n, nn));
}