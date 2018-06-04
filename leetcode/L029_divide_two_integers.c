//
// Created by zxwtry on 2018/6/3.
//


#include <stdlib.h>
#include <stdio.h>

long long L029_divide_long(long long d, long long r) {
    if (d < r) {
        return 0;
    }
    long long times = 1;
    long long val = r;
    while (val + val <= d) {
        times += times;
        val += val;
    }
    return times + L029_divide_long(d - val, r);
}


// Ac 20ms 53.33 %
int L029_divide(int dividend, int divisor) {
    if (divisor == 1) {
        return dividend;
    }
    if (divisor == -1) {
        return dividend == INT_MIN ? 0 : - dividend;
    }
    if (divisor == 0) {
        return 0;
    }
    long long d = dividend;
    long long r = divisor;
    d = d < 0 ? -d : d;
    r = r < 0 ? -r : r;
    long long ans = L029_divide_long(d, r);
    if ( (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ) {
        ans = - ans;
    }
    return (int) ans;
}


void L029() {
    int d = INT_MIN;
    int r = -1;
    printf("a is %d\n", L029_divide(d, r));
    //printf("a is %d\n", (d / r));
}