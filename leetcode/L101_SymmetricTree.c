/*
    url: leetcode.com/problems/symmetric-tree
    AC 3ms 23.58%
*/

#include <stdio.h>
#include <stdlib.h>

struct L101_TreeNode {
    int val;
    struct L101_TreeNode *left;
    struct L101_TreeNode *right;
};

#define bool int



typedef struct L101_TreeNode stn;
typedef struct L101_TreeNode * ptn;

typedef ptn T;
typedef struct L101_al sal;
typedef struct L101_al * pal;

struct L101_al {
    int capacity;
    int size;
    T* arr;
};

pal L101_al_init(int capacity) {
    pal l = (pal) malloc(sizeof(sal));
    if (capacity < 1) return NULL;
    l->arr = (T*) malloc(sizeof(T) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L101_al_expand_capacity(pal l) {
    T* new_arr = (T*) malloc(sizeof(T) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L101_al_add_last(pal l, T v) {
    if (l->capacity == l->size) L101_al_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

void L101_al_free_all(pal l) {
    free(l->arr);
    free(l);
}

void L101_swap(pal* l1, pal* l2) {
    pal l = *l1;
    *l1 = *l2;
    *l2 = l;
}

int L101_cmp(ptn l1, ptn l2) {
    if (l1 == NULL || l2 == NULL)
        return l1 == NULL && l2 == NULL;
    return l1->val == l2->val;
}

bool L101_isSymmetric(struct L101_TreeNode* root) {
    pal l1 = NULL, l2 = NULL;
    int i = 0, j = 0;
    if (root == NULL) return 1;
    l1 = L101_al_init(16);
    l2 = L101_al_init(16);
    L101_al_add_last(l1, root);
    while (l1->size != 0) {
        l2->size = 0;
        for (i = 0; i < l1->size; i ++) {
            if (l1->arr[i] != NULL) {
                L101_al_add_last(l2, l1->arr[i]->left);
                L101_al_add_last(l2, l1->arr[i]->right);
            }
        }
        i = 0;
        j = l2->size - 1;
        while (i < j) {
            if (! L101_cmp(l2->arr[i], l2->arr[j]))
                return 0;
            i ++;
            j --;
        }
        L101_swap(&l1, &l2);
    }
    L101_al_free_all(l1);
    L101_al_free_all(l2);
    return 1;
}