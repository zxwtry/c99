/*
    url: leetcode.com/problems/single-number
    AC 6ms 15.50%
*/

#include <stdio.h>
#include <stdlib.h>

int L136_singleNumber(int* n, int nn) {
    int ans = 0, i = 0;
    for (i = 0; i < nn; i ++) {
        ans ^= n[i];
    }
    return ans;
}

int L136() {
    int n[] = {1, 2, 2, 1, 3 ,4, 4};
    int nn = 7;
    printf("answer is %d\n", L136_singleNumber(n, nn));
}