/*
    url: leetcode.com/problems/first-missing-positive/
    firstMissingPositive:   AC 3ms 38.60%
    firstMissingPositive2:  AC 6ms  5.26% 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int L041_firstMissingPositive(int* n, int s) {
    char* m = (char*) malloc(sizeof(char) * (s + 2));
    int i = 0;
    memset(m, '0', s + 2);
    for (i = 0; i < s; i ++) {
        if (n[i] >= 1 && n[i] <= s)
            m[n[i]] = '1';
    }
    for (i = 1; i <= s; i ++) {
        if (m[i] == '0') break;
    }
    free(m);
    return i;
}

void L041_swap(int* a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int L041_firstMissingPositive2(int* n, int s) {
    int i = 0;
    for (i = 0; i < s; i ++) {
        while (n[i] > 0 && n[i] <= s && n[n[i] - 1] != n[i])
            L041_swap(n + i, n + n[i] - 1);
    }
    for (i = 0; i < s; i ++) {
        if (n[i] != i + 1)
            return i + 1;
    }
    return s + 1;
}


int L041() {
    int n[] = {3,4,-1,1};
    int s = 4;
    printf("answer is %d\r\n", L041_firstMissingPositive2(n , s));
}
