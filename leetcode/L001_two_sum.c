//
// Created by zxwtry on 2017/11/14.
//

#include <stdlib.h>
#include <stdio.h>

/*
    url: https://leetcode.com/problems/two-sum/description/

 */


//AC 99ms 64.07%
int* L001_01_twoSum(int* ns, int nn, int t) {
    int i = 0, j = 0;
    int* ret = (int *) malloc(2 * sizeof(int));
    for (i = 0; i < nn; i ++) {
        for (j = i + 1; j < nn; j ++) {
            if (ns[i] + ns[j] == t) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return ret;
}

int* L001_02_twoSum(int* ns, int nn, int t) {
    int* ret = (int *) malloc(2 * sizeof(int));

    return ret;
}



void L001() {
    int nn = 9;
    int ns[] = {2, 7, 11, 15};
    int t = 9;
    int* ans = L001_01_twoSum(ns, nn, t);
    printf("%d %d\n", ans[0], ans[1]);
    free(ans);
}