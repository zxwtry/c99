/*
    url: leetcode.com/problems/jump-game/
    AC 6ms 31.34%
*/

#include <stdio.h>
#include <stdlib.h>

#define bool int

#define max(a, b) ((a) < (b) ? (b) : (a))


bool L055_canJump(int* n, int nn) {
    int mti = 0, i = 0;
    for (i = 0; i < nn; i ++) {
        if (mti < i) return 0;
        mti = max(mti, n[i] + i);
        if (mti > nn-1) return 1;
    }
    return 1;
}

int L055() {
    int n[] = {3,2,1,0,4};
    int nn = 5;
    printf("answer is %d\r\n", L055_canJump(n, nn));
}