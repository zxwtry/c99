/*
    url: leetcode.com/problems/restore-ip-addresses
    AC 0ms 87.50%
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* T;
typedef struct L093_al sal;
typedef struct L093_al * pal;

struct L093_al {
    int capacity;
    int size;
    T* arr;
};

pal L093_al_init(int capacity) {
    pal l = (pal) malloc(sizeof(sal));
    if (capacity < 1) return NULL;
    l->arr = (T*) malloc(sizeof(T) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L093_al_expand_capacity(pal l) {
    T* new_arr = (T*) malloc(sizeof(T) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L093_al_add_last(pal l, T v) {
    if (l->capacity == l->size) L093_al_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

T* L093_al_convert_to_array_free_l(pal l) {
    T* arr = l->arr;
    free(l);
    return arr;
}

void L093_al_print(pal l) {
    int i = 0;
    if (l->size == 0) return;
    printf("================\r\n");
    for (i = 0; i < l->size; i ++)
        printf("%s\r\n", l->arr[i]);
    printf("================\r\n");
    printf("\r\n");
}

char* L093_char_copy(char* r, int rn) {
    char* copy = (char*) malloc(sizeof(char) * rn);
    int i = 0;
    for (i = 0; i < rn-1; i ++)
        copy[i] = r[i];
    copy[rn-1] = '\0';
    return copy;
}

void L093_search(pal l, char* s, int si, int sn, char* r, int ri, int rn, int cnt) {
    int v = 0, i = 0;
    if (si == sn && ri == rn && cnt == 4) {
        L093_al_add_last(l, L093_char_copy(r, rn));
        return ;
    }
    if (si >= sn || ri >= rn || cnt >= 4) return;
    for (i = 0; i < 3 && si+i < sn; i ++) {
        v = v * 10 + s[si + i] - '0';
        if (v > 255) break;
        r[ri+i] = s[si+i];
        r[ri+i+1] = '.';
        L093_search(l, s, si+i+1, sn, r, ri+i+2, rn, cnt+1);
        if (i == 0 && v == 0) break;
    }
} 

char** L093_restoreIpAddresses(char* s, int* rn) {
    pal l = L093_al_init(16);
    int sn = s == NULL ? 0 : strlen(s);
    char* r = NULL;
    if (sn < 4 || sn > 12) return NULL;
    r = (char*) malloc(sizeof(char) * (sn + 4));
    L093_search(l, s, 0, sn, r, 0, sn+4, 0);
    free(r);
    *rn = l->size;
    return L093_al_convert_to_array_free_l(l);
}

int L093() {
    /*
        0000            --->  0.0.0.0
        00000           --->  NULL
        25525511135     --->  [255.255.11.135, 255.255.111.35]
        123892398       --->  [123.89.23.98, 123.89.239.8]
        255255255255    --->  [255.255.255.255]
    */
    char* s = "0000";
    int rn = 0;
    char** a = L093_restoreIpAddresses(s, &rn);
    int i = 0;
    for (i = 0; i < rn; i ++) {
        printf("%s\r\n", a[i]);
        free(a[i]);
    }
    free(a);
    return 0;
}