//
// Created by zxwtry on 2018/6/2.
//


#include <mem.h>
#include <stdlib.h>
#include <stdio.h>


void L028_get_next(char* p, int pn, int * next) {
    if (pn < 1) {
        return;
    }
    if (pn < 2) {
        next[0] = -1;
        return;
    }
    next[0] = -1;
    next[1] = 0;
    int bi = 0, fi = 2;
    while (fi < pn) {
        if (p[bi] == p[fi - 1]) {
            next[fi ++] = ++ bi;
        } else if (bi <= 0) {
            next[fi ++] = 0;
        } else {
            bi = next[bi];
        }
    }
}


// AC 4ms 89.74 %
int L028_strStr(char* s, char* p) {
    int sn = strlen(s);
    int pn = strlen(p);
    if (pn < 1) {
        return 0;
    } else if (sn < pn) {
        return -1;
    }
    int * next = (int *) malloc(sizeof(int) * pn);
    int si = 0, pi = 0;
    L028_get_next(p, pn, next);
    while (si < sn) {
        if (s[si] == p[pi]) {
            si ++;
            pi ++;
            if (pi == pn) {
                break;
            }
        } else if (next[pi] == -1) {
            si ++;
        } else {
            pi = next[pi];
        }
    }
    free(next);
    return pi == pn ? si - pn : -1;
}


void L028() {
    /*
     "mississippi"
     "issip"
     */
    char * s = "mississippi";
    char * p = "issip";
    int index = L028_strStr(s, p);
    printf("ans is %d\n", index);
}