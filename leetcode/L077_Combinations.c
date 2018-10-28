/*
    url: leetcode.com/problems/combinations/
    AC 33ms 97.06%
*/

#include <stdio.h>
#include <stdlib.h>

typedef int* T;
typedef struct L077_al sal;
typedef struct L077_al * pal;

struct L077_al {
    int capacity;
    int size;
    T* arr;
};

pal L077_al_init(int capacity) {
    pal l = (pal) malloc(sizeof(sal));
    if (capacity < 1) return NULL;
    l->arr = (T*) malloc(sizeof(T) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L077_al_expand_capacity(pal l) {
    T* new_arr = (T*) malloc(sizeof(T) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L077_al_add_last(pal l, T v) {
    if (l->capacity == l->size) L077_al_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

T* L077_al_convert_to_array_free_l(pal l) {
    T* arr = l->arr;
    free(l);
    return arr;
}

int* L077_arr_copy(int* save, int n) {
    int* copy = (int*) malloc(sizeof(int) * n);
    int i = 0;
    for (i = 0; i < n; i ++)
        copy[i] = save[i];
    return copy;
}

void L077_search(int ni, int n, int* save, int si, int sn, pal l) {
    int k = 0;
    if (si == sn) {
        L077_al_add_last(l, L077_arr_copy(save, sn));
        return;
    }
    for (k = ni; k <= n; k ++) {
        save[si] = k;
        L077_search(k+1, n, save, si+1, sn, l);
    }
}

int** L077_combine(int n, int k, int** cn, int* ren) {
    pal l = L077_al_init(16);
    int i = 0;
    int* save = (int*) malloc(sizeof(int) * k);
    L077_search(1, n, save, 0, k, l);
    *ren = l->size;
    *cn = (int*) malloc(sizeof(int) * l->size);
    for (i = 0; i < l->size; i ++)
        (*cn)[i] = k;
    return L077_al_convert_to_array_free_l(l);
}