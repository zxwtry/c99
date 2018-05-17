//
// Created by zxwtry on 2018/5/16.
//

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <mem.h>

// 简单处理方法，转换成long long
// AC 16ms  73.96 %
long long L007_01_solve_long(long long x) {
    if (x < 0) {
        return - L007_01_solve_long(- x);
    }
    long long v = 0;
    while (x != 0) {
        v = v * 10 + (x % 10);
        x = x / 10;
    }
    return v;
}

int L007_01_reverse(int x) {
    long long v = x;
    long long a = L007_01_solve_long(v);
    if (a < INT_MIN || a >= INT_MAX) {
        return 0;
    } else {
        return (int) a;
    }
}


void swap(char* s, int i, int j) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
}

void L007_itoa(int x, char * s, int radix) {
    char cs[15];
    int csIndex = 13;
    int v = 0;
    int sIndex = 0;
    int isNegative = x < 0;
    while (x != 0) {
        v = x % 10;
        if (isNegative) {
            v = -v;
        }
        cs[csIndex --] = (char) ('0' + v);
        x = x / 10;
    }
    csIndex ++;
    if (isNegative) {
        s[sIndex ++] = '-';
    }
    while (csIndex < 14) {
        s[sIndex ++] = cs[csIndex ++];
    }
    s[sIndex] = '\0';
}

// 采用计算的方法
// AC 16ms 73.96 %
int L007_02_reverse(int x) {
    char s[15];
    itoa(x, s, 10);
    int sn = strlen(s);
    int startIndex = x < 0 ? 1 : 0;
    int i = startIndex;
    int j = sn - 1;
    int v = 0;
    while (i < j) {
        swap(s, i ++, j --);
    }
    if (x < 0) {
        int limit1 = INT_MIN / 10;
        int limit2 = INT_MIN % 10;
        int add = 0;
        for (i = startIndex; i < sn; ++ i) {
            add = - s[i] + '0';
            if (v < limit1 || (v == limit1 && add < limit2)) {
                return 0;
            }
            v = v * 10 + add;
        }
    } else {
        int limit1 = INT_MAX / 10;
        int limit2 = INT_MAX % 10;
        int add = 0;
        for (i = startIndex; i < sn; ++ i) {
            add = s[i] - '0';
            if (v > limit1 || (v == limit1 && add > limit2)) {
                return 0;
            }
            v = v * 10 + add;
        }
    }
    return v;
}

void L007() {
    int v = INT_MAX;
    char s[15];
    itoa(v, s, 10);
    printf("ans string is %s\n", s);
    printf("ans is %d\n", v % 10);
    L007_itoa(v, s, 10);
    printf("itoa is %s\n", s);
}