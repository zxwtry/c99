/*
    url: leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
    on_n:   AC 3ms 43.33%
    on_n_2: AC 3ms 43.33%
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


void L123_swap(int* a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void L123_heap_up(int* h, int j) {
    int p = (j-1) / 2, c = j;
    while (p != c) {
        if (h[p] > h[c]) {
            L123_swap(h+p, h+c);
            c = p;
            p = (c-1) / 2;
        } else break;
    }
}

void L123_heap_dn(int* h, int hn, int i) {
    int p = 0, c = 1;
    while (c < hn) {
        if (c+1 < hn && h[c+1] < h[c]) c ++;
        if (h[p] > h[c]) {
            L123_swap(h+p, h+c);
            p = c;
            c = 2*p + 1;
        } else break;
    }
}

void L123_heap_add(int* h, int *hi, int hn, int v) {
    if ((*hi) != hn) {
        h[*hi] = v;
        L123_heap_up(h, *hi);
        (*hi) ++;
    } else {
        if (v > h[0]) {
            h[0] = v;
            L123_heap_dn(h, hn, 0);
        }
    }
}

//TLE
int L123_onn_nn(int* p, int pn) {
    int** m = NULL, i = 0, j = 0;
    int iv = 0, jv = 0, ans = 0;
    if (pn < 2) return 0;
    m = (int**) malloc(sizeof(int*) * pn);
    for (i = 0; i < pn; i ++)
        m[i] = (int*) malloc(sizeof(int) * pn);
    for (i = 0; i < pn ; i ++) m[i][i] = 0;
    for (i = 0; i < pn; i ++) {
        iv = p[i];
        for (j = i+1; j < pn; j ++) {
            jv = p[j];
            if (jv - iv > m[i][j-1])
                m[i][j] = jv - iv;
            else m[i][j] = m[i][j-1];
        }
    }
    for (i = 0; i < pn; i ++) {
        for (j = i+2; j < pn; j ++) {
            ans = max(ans, m[i][j-1]+m[j][pn-1]);
        }
        ans = max(ans, m[i][pn-1]);
    }
    return ans;
}

int L123_on_n(int* p, int pn) {
    int* l = (int*) malloc(sizeof(int) * (pn+1));
    int* r = (int*) malloc(sizeof(int) * (pn+1));
    int i = 0, mv = INT_MAX, m = 0, ans = 0;
    l[0] = 0;
    for (i = 1; i <= pn; i ++) {
        mv = min(p[i-1], mv);
        m = max(m, p[i-1]-mv);
        l[i] = m;
    }
    mv = INT_MIN;
    m = 0;
    r[pn] = 0;
    for (i = pn-1; i > -1; i --) {
        mv = max(p[i], mv);
        m = max(m, mv-p[i]);
        r[i] = m;
    }
    for (i = 0; i <= pn; i ++) {
        ans = max(ans, l[i]+r[i]);
    }
    free(l);
    free(r);
    return ans;
}

int L123_on_n_2(int* p, int pn) {
    int* l = (int*) malloc(sizeof(int) * (pn+1));
    int i = 0, mv = INT_MAX, m = 0, ans = 0;
    l[0] = 0;
    for (i = 1; i <= pn; i ++) {
        mv = min(p[i-1], mv);
        m = max(m, p[i-1]-mv);
        l[i] = m;
    }
    mv = INT_MIN;
    m = 0;
    for (i = pn-1; i > -1; i --) {
        mv = max(p[i], mv);
        m = max(m, mv-p[i]);
        ans = max(ans, l[i]+m);
    }
    ans = max(ans, l[pn] + 0);
    free(l);
    return ans;
}

int L123_maxProfit(int* p, int pn) {
    return L123_on_n_2(p, pn);
}

int L123() {
    int p[] = {1, 7, 2, 9, 3, 11, 4, 13, 5, 15};
    int pn = 10;
    printf("answer is %d\n", L123_maxProfit(p, pn));
    return 0;
}