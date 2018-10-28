/*
    url: leetcode.com/problems/binary-tree-level-order-traversal-ii
    AC 3ms 28.85%
*/

#include <stdio.h>
#include <stdlib.h>

struct L107_TreeNode {
    int val;
    struct L107_TreeNode *left;
    struct L107_TreeNode *right;
};

typedef struct L107_TreeNode * ptn;
typedef struct L107_TreeNode stn;

typedef int* T;
typedef struct L107_al sal;
typedef struct L107_al * pal;

struct L107_al {
    int capacity;
    int size;
    T* arr;
};

pal L107_al_init(int capacity) {
    pal l = (pal) malloc(sizeof(sal));
    if (capacity < 1) return NULL;
    l->arr = (T*) malloc(sizeof(T) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L107_al_expand_capacity(pal l) {
    T* new_arr = (T*) malloc(sizeof(T) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L107_al_add_last(pal l, T v) {
    if (l->capacity == l->size) L107_al_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

void L107_al_free_all(pal l) {
    int i = 0;
    for (i = 0; i < l->size; i ++)
        free(l->arr[i]);
    free(l->arr);
    free(l);
}

T* L107_al_convert_to_array_free_l(pal l) {
    T* arr = l->arr;
    free(l);
    return arr;
}

typedef ptn V;
typedef struct L107_sl ssl;
typedef struct L107_sl * psl;

struct L107_sl {
    int capacity;
    int size;
    V* arr;
};

psl L107_sl_init(int capacity) {
    psl l = (psl) malloc(sizeof(ssl));
    if (capacity < 1) return NULL;
    l->arr = (V*) malloc(sizeof(V) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L107_sl_expand_capacity(psl l) {
    V* new_arr = (V*) malloc(sizeof(V) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L107_sl_add_last(psl l, V v) {
    if (l->capacity == l->size) L107_sl_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

void L107_sl_free_all(psl l) {
    free(l->arr);
    free(l);
}


void L107_swap_psl(psl* l1, psl* l2) {
    psl l = *l1;
    *l1 = *l2;
    *l2 = l;
}

void L107_swap_int_star(int** a, int** b) {
    int* c = *a;
    *a = *b;
    *b = c;
}

void L107_reverse(pal l) {
    int i = 0, j = l->size - 1;
    while (i < j) {
        L107_swap_int_star(&(l->arr[i]), &(l->arr[j]));
        i ++;
        j --;
    }
}

int** L107_levelOrderBottom(ptn n, int** cn, int* rn) {
    psl l1 , l2 ;
    int i = 0, i2 = 0, *t = NULL; 
    pal l = NULL, ln = NULL;
    if (n == NULL) return NULL;
    l1 = L107_sl_init(16);
    l2 = L107_sl_init(16);
    l = L107_al_init(16);
    ln = L107_al_init(16);
    L107_sl_add_last(l1, n);
    while (l1->size != 0) {
        t = (int*) malloc(sizeof(int) * l1->size);
        for (i = 0; i < l1->size; i ++)
            t[i] = l1->arr[i]->val;
        L107_al_add_last(l, t);
        t = (int*) malloc(sizeof(int) * 1);
        t[0] = l1->size;
        L107_al_add_last(ln, t);
        l2->size = 0;
        for (i = 0; i < l1->size; i ++) {
            if (l1->arr[i]->left != NULL)
                L107_sl_add_last(l2, l1->arr[i]->left);
            if (l1->arr[i]->right != NULL)
                L107_sl_add_last(l2, l1->arr[i]->right);
        }
        L107_swap_psl(&l1, &l2);
    }
    L107_sl_free_all(l1);
    L107_sl_free_all(l2);
    *cn = (int*) malloc(sizeof(int) * ln->size);
    for (i = 0; i < ln->size; i ++)
        (*cn)[ln->size - 1- i] = ln->arr[i][0];
    L107_al_free_all(ln);
    *rn = l->size;
    L107_reverse(l);
    return L107_al_convert_to_array_free_l(l);
}