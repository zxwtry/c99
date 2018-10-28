/*
    url: leetcode.com/problems/divide-two-integers/
    16ms 48.96%
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//for vc6   printf use I64d
#define LL __int64_t


int L029_d(LL a, LL b) {
    int count = 0;
    LL add1 = 0;
    int ans = 0;
    LL add = 0;
    if (b == 1) return a;
    while (add <= a) {
        add1 = b;
        count = 1;
        while (add + add1 + add1 < a) {
            add1 = add1 + add1;
            count = count + count;
        }
        add += add1;
        
        ans += count;
    }   
    return ans - 1;
}

int L029_divide(int a, int b) {
    int sign = 0, ans = 0;
    LL aa = a;
    LL bb = b;
    if (b == 0 || (a == INT_MIN && b == -1))
        return INT_MAX;
    sign = (a ^ b) >> 31;
    aa = aa < 0 ? -aa : aa;
    bb = bb < 0 ? -bb : bb;
    //printf("%I64d\t%I64d\r\n", aa, bb);
    return sign ? -L029_d(aa, bb) : L029_d(aa, bb);
}

int L029() {
    printf("%d\r\n", L029_divide(34, 4));
}

