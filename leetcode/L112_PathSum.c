/*
    url: leetcode.com/problems/path-sum
    AC 6ms 27.83%
*/

#include <stdio.h>
#include <stdlib.h>

struct L112_TreeNode {
    int val;
    struct L112_TreeNode *left;
    struct L112_TreeNode *right;
};

typedef int bool;

typedef struct L112_TreeNode stn;
typedef struct L112_TreeNode * ptn;


ptn L112_tn_init(int val) {
    ptn n = (ptn) malloc(sizeof(stn));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

typedef ptn T;
typedef struct L112_al sal;
typedef struct L112_al * pal;

struct L112_al {
    int capacity;
    int size;
    T* arr;
};

pal L112_al_init(int capacity) {
    pal l = (pal) malloc(sizeof(sal));
    if (capacity < 1) return NULL;
    l->arr = (T*) malloc(sizeof(T) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L112_al_expand_capacity(pal l) {
    T* new_arr = (T*) malloc(sizeof(T) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L112_al_add_last(pal l, T v) {
    if (l->capacity == l->size) L112_al_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

void L112_al_free_all(pal l) {
    free(l->arr);
    free(l);
}

void L112_swap_al(pal* l1, pal* l2) {
    pal t = *l1;
    *l1 = *l2;
    *l2 = t;
}

void L112_search(ptn n, int c, int s, int* sign) {
    if (*sign) return;
    if (n == NULL) return;
    search(n->left, c+n->val, s, sign);
    search(n->right, c+n->val, s, sign);
    if (n->left == NULL && n->right == NULL && c+n->val == s) *sign=1;
}

bool L112_hasPathSum(ptn n, int s) {
    int c = 0, sign = 0;
    search(n, 0, s, &sign);
    return sign;
}