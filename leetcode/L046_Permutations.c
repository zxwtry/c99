/*
    url: leetcode.com/problems/permutations/
    AC 9ms 20.00%
*/


#include <stdio.h>
#include <stdlib.h>

int* L046_arr_copy_of(int* n, int ns) {
    int* ans = (int*) malloc(sizeof(int) * ns);
    int i = 0;
    for (i = 0; i < ns; i ++)
        ans[i] = n[i];
    return ans;
}

void L046_swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void L046_search(int** ans, int* ansIndex, int* n, int ni, int ns) {
    int i = 0;
    if (ni == ns) {
        ans[(*ansIndex) ++] = L046_arr_copy_of(n, ns);
        return;
    }
    for (i = ni; i < ns; i ++) {
        L046_swap(n+i, n+ni);
        L046_search(ans, ansIndex, n, ni+1, ns);
        L046_swap(n+i, n+ni);
    }
}

int** L046_permute(int* n, int s, int* rs) {
    int len = 1, i = 0, ** ans = NULL, ansIndex = 0;
    for (i = s; i > 1; i --) len *= i;
    ans = (int**) malloc(sizeof(int*) * len);
    L046_search(ans, &ansIndex, n, 0, s);
    *rs = len;
    return ans;
}

int L046() {
    int n[] = {1, 2, 3};
    int s = 3;
    int rs = 0;
    int** ans = L046_permute(n, s, &rs);
    int i = 0, j = 0;
    for (i = 0; i < rs; i ++) {
        for (j = 0; j < s; j ++)
            printf("%d ", ans[i][j]);
        printf("\r\n");
        free(*(ans+i));
    }
    free(ans);    
}