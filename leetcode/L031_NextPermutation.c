/*
    url: leetcode.com/problems/next-permutation/
    9ms 22.22%
*/

#include <stdio.h>
#include <stdlib.h>

void L031_print_array(int * n, int ns) {
    int i = 0;
    for (i = 0; i < ns; i ++)
        printf("%d ", n[i]);
    printf("\r\n");
}

void L031_swap(int * a, int * b) {
    int t = * a;
    * a = * b;
    * b = t;
}

//[i, j)
void L031_reverse(int * n, int i, int j) {
    j --;
    while (i < j) L031_swap(n + (i ++), n + (j --));
}

//[i, j)
int L031_binary_search_little_bigger(int * n, int i, int j, int v) {
    int m = 0;
    j --;
    while (i < j) {
        //same with (i + j + 1) / 2
        m = i + (j - i + 1) / 2;
        if (n[m] > v) {
            i = m;
        } else {
            j = m - 1;
        }
    }
    return i;
}

void L031_nextPermutation(int* n, int ns) {
    int i = 0, j = 0;
    for (i = ns - 2; i > -1 && n[i] >= n[i + 1]; i --) {};
    if (i == -1) {
        L031_reverse(n, 0, ns);
    } else {
        L031_swap(n + i, n + L031_binary_search_little_bigger(n, i + 1, ns, n[i]));
        L031_reverse(n, i + 1, ns);
    }
}

int L031() {
    int n[] = {3, 4, 3, 2, 1};
    int ns = 5;
    L031_nextPermutation(n, ns);
    L031_print_array(n, ns);
    return 0;
}