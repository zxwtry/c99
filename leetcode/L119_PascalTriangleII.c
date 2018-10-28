#include <malloc.h>

/*
    url: leetcode.com/problems/pascals-triangle-ii
    AC 3ms 2.56%
*/

void L119_swap(int** a, int** b) {
    int* t = *a;
    *a = *b;
    *b = t;
}

int* L119_getRow(int ri, int* rn) {
    int* ans = (int*) malloc(sizeof(int) * (ri+1));
    int* tmp = (int*) malloc(sizeof(int) * (ri+1));
    int i = 0, j = 0, k = 0;
    for (i = 0; i <= ri; i ++) {
        ans[0] = 1;
        for (j = 1; j <= i; j ++) {
            ans[j] = tmp[j] + tmp[j-1];
        }
        ans[i] = 1;
        L119_swap(&ans, &tmp);
    }
    free(ans);
    *rn = ri+1;
    return tmp;
}