//
// Created by zxwtry on 2018/6/3.
//


#include <stdlib.h>

long long L029_divide_long(long long d, long long r) {
    if (d < r) {
        return 0;
    }

}

int L029_divide(int dividend, int divisor) {
    if (divisor == 1 || divisor == -1) {
        return divisor == 1 ? dividend : - dividend;
    }
    if (divisor == 0) {
        return 0;
    }
    long long d = dividend;
    long long r = divisor;
    d = d < 0 ? -d : d;
    r = r < 0 ? -r : r;
    long long ans = L029_divide_long(d, r);
    if ( (dividend < 0 && divisor > 0) || (dividend < 0 && divisor > 0) ) {
        ans = - ans;
    }
    if (ans < INT_MIN || ans > INT_MAX) {
        return 0;
    }
    return (int) ans;
}