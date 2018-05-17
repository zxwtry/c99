//
// Created by zxwtry on 2018/5/17.
//

#include <stdbool.h>
#include <stdio.h>


// AC 196ms 34.51 %
bool L009_isPalindrome(int x) {
    if (x < 0) return 0;
    int v = 0;
    int s = x;
    while (x != 0) {
        v = v * 10 + (x % 10);
        x = x / 10;
    }
    return s == v;
}

void L009() {
    int a [] = {
            -10,
            1,
            121,
            123,
            1999
    };
    for (int i = 0; i < 4; ++i) {
        printf("v:%d\tisP:%d\n", a[i], L009_isPalindrome(a[i]));
    }
}