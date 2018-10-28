/*
    url: leetcode.com/problems/binary-tree-zigzag-level-order-traversal
    AC 3ms 14.29%
*/


#include <stdio.h>
#include <stdlib.h>

struct L103_TreeNode {
    int val;
    struct L103_TreeNode *left;
    struct L103_TreeNode *right;
};

typedef struct L103_TreeNode stn;
typedef struct L103_TreeNode * ptn;

typedef int* T;
typedef struct L103_al sal;
typedef struct L103_al * pal;

struct L103_al {
    int capacity;
    int size;
    T* arr;
};

pal L103_al_init(int capacity) {
    pal l = (pal) malloc(sizeof(sal));
    if (capacity < 1) return NULL;
    l->arr = (T*) malloc(sizeof(T) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L103_al_expand_capacity(pal l) {
    T* new_arr = (T*) malloc(sizeof(T) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L103_al_add_last(pal l, T v) {
    if (l->capacity == l->size) L103_al_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

void L103_al_free_all(pal l) {
    int i = 0;
    for (i = 0; i < l->size; i ++)
        free(l->arr[i]);
    free(l->arr);
    free(l);
}

T* L103_al_convert_to_array_free_l(pal l) {
    T* arr = l->arr;
    free(l);
    return arr;
}

typedef ptn V;
typedef struct L103_sl ssl;
typedef struct L103_sl * psl;

struct L103_sl {
    int capacity;
    int size;
    V* arr;
};

psl L103_sl_init(int capacity) {
    psl l = (psl) malloc(sizeof(ssl));
    if (capacity < 1) return NULL;
    l->arr = (V*) malloc(sizeof(V) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L103_sl_expand_capacity(psl l) {
    V* new_arr = (V*) malloc(sizeof(V) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L103_sl_add_last(psl l, V v) {
    if (l->capacity == l->size) L103_sl_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

void L103_sl_free_all(psl l) {
    free(l->arr);
    free(l);
}

void L103_swap_psl(psl* l1, psl* l2) {
    psl l = *l1;
    *l1 = *l2;
    *l2 = l;
}

int** L103_zigzagLevelOrder(ptn n, int** cn, int* rn) {
    psl l1 , l2 ;
    int i = 0, i2 = 0, *t = NULL, s = 1; 
    pal l = NULL, ln = NULL;
    if (n == NULL) return NULL;
    l1 = L103_sl_init(16);
    l2 = L103_sl_init(16);
    l = L103_al_init(16);
    ln = L103_al_init(16);
    L103_sl_add_last(l1, n);
    while (l1->size != 0) {
        t = (int*) malloc(sizeof(int) * l1->size);
        for (i = 0; i < l1->size; i ++) {
            if (s) t[i] = l1->arr[i]->val;
            else t[l1->size - 1 - i] = l1->arr[i]->val;
        }
        L103_al_add_last(l, t);
        t = (int*) malloc(sizeof(int) * 1);
        t[0] = l1->size;
        L103_al_add_last(ln, t);
        l2->size = 0;
        for (i = 0; i < l1->size; i ++) {
            if (l1->arr[i]->left != NULL)
                L103_sl_add_last(l2, l1->arr[i]->left);
            if (l1->arr[i]->right != NULL)
                L103_sl_add_last(l2, l1->arr[i]->right);
        }
        L103_swap_psl(&l1, &l2);
        s = !s;
    }
    L103_sl_free_all(l1);
    L103_sl_free_all(l2);
    *cn = (int*) malloc(sizeof(int) * ln->size);
    for (i = 0; i < ln->size; i ++)
        (*cn)[i] = ln->arr[i][0];
    L103_al_free_all(ln);
    *rn = l->size;
    return L103_al_convert_to_array_free_l(l);
}