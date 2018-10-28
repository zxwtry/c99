/*
    url: leetcode.com/problems/subsets/
    AC 3ms 47.37%
*/

#include <stdio.h>
#include <stdlib.h>

typedef int* T;
typedef struct L078_al sal;
typedef struct L078_al * pal;

struct L078_al {
    int capacity;
    int size;
    T* arr;
};

pal L078_al_init(int capacity) {
    pal l = (pal) malloc(sizeof(sal));
    if (capacity < 1) return NULL;
    l->arr = (T*) malloc(sizeof(T) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L078_al_expand_capacity(pal l) {
    T* new_arr = (T*) malloc(sizeof(T) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L078_al_add_last(pal l, T v) {
    if (l->capacity == l->size) L078_al_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

T* L078_al_convert_to_array_free_l(pal l) {
    T* arr = l->arr;
    free(l);
    return arr;
}

int* L078_arr_copy(int* save, int n) {
    int* copy = (int*) malloc(sizeof(int) * n);
    int i = 0;
    for (i = 0; i < n; i ++)
        copy[i] = save[i];
    return copy;
}

//[l, r]
int L078_partition(int* n, int l, int r) {
    int s = *(n + l);
    while (l < r) {
        while (l < r && *(n + r) >= s) r --;
        *(n + l) = *(n + r);
        while (l < r && *(n + l) <= s) l ++;
        *(n + r) = *(n + l);
    }
    *(n + l) = s;
    return l;
}

//[l, r)
void L078_quick_sort(int* n, int l, int r) {
    int p = 0;
    if (l < r) {
        p = L078_partition(n, l, r - 1);
        L078_quick_sort(n, l, p);
        L078_quick_sort(n, p + 1, r);
    }
}

void L078_search(int* n, int ni, int nn, int* save, int si, int sn, pal l, pal ln) {
    int* t = NULL;
    int i = 0;
    if (si == sn) {
        L078_al_add_last(l, L078_arr_copy(save, sn));
        t = (int*) malloc(sizeof(int));
        t[0] = sn;
        L078_al_add_last(ln, t);
        return;
    }
    for (i = ni; i < nn; i ++) {
        if (i != 0 && n[i-1] == n[i]) continue;
        save[si] = n[i];
        L078_search(n, i+1, nn, save, si+1, sn, l, ln);
    }
}

int** L078_subsets(int* n, int nn, int** cn, int* rn) {
    int ni = 0;
    int* save = (int*) malloc(sizeof(int) * nn);
    int sn = 0;
    pal l = L078_al_init(16);
    pal ln = L078_al_init(16);
    L078_quick_sort(n, 0, nn);
    for (sn = 0; sn <= nn; sn ++) {
        L078_search(n, 0, nn, save, 0, sn, l, ln);
    }
    *cn = (int*) malloc(sizeof(int) * ln->size);
    *rn = ln->size;
    for (ni = 0; ni < ln->size; ni ++) {
        (*cn)[ni] = ln->arr[ni][0];
    }
    return L078_al_convert_to_array_free_l(l);
}

int L078() {
    int n[] = {1, 2, 3};
    int nn = 3;
    int* cn = NULL;
    int rn = 0;
    int** ans = L078_subsets(n, nn, &cn, &rn);
    printf("size is %d\r\n", rn);
}