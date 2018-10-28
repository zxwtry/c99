/*
    url: leetcode.com/problems/unique-binary-search-trees-ii
    AC 6ms 100.00%
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct L095_TreeNode stn;
typedef struct L095_TreeNode * ptn;

struct L095_TreeNode {
    int val;
    ptn left;
    ptn right;
};

ptn L095_tn_init(int val) {
    ptn n = (ptn) malloc(sizeof(stn));
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    return n;
}

void L095_tn_free(ptn n) {
    if (n == NULL) return;
    L095_tn_free(n->left);
    L095_tn_free(n->right);
    free(n);
}

typedef ptn T;
typedef struct L095_al sal;
typedef struct L095_al * pal;

struct L095_al {
    int capacity;
    int size;
    T* arr;
};

pal L095_al_init(int capacity) {
    pal l = (pal) malloc(sizeof(sal));
    if (capacity < 1) return NULL;
    l->arr = (T*) malloc(sizeof(T) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L095_al_expand_capacity(pal l) {
    T* new_arr = (T*) malloc(sizeof(T) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L095_al_add_last(pal l, T v) {
    if (l->capacity == l->size) L095_al_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

T* L095_al_convert_to_array_free_l(pal l) {
    T* arr = l->arr;
    free(l);
    return arr;
}

void L095_al_free(pal l) {
    int i = 0;
    for (i = 0; i < l->size; i ++) {
        if (l->arr[i] != NULL)
            L095_tn_free(l->arr[i]);
    }
    free(l->arr);
    free(l);
}

ptn L095_tn_copy_offset(ptn n, int offset) {
    ptn root = NULL;
    if (n == NULL) return NULL;
    root = L095_tn_init(n->val + offset);
    root->left = L095_tn_copy_offset(n->left, offset);
    root->right = L095_tn_copy_offset(n->right, offset);
    return root;
}

ptn* L095_generateTrees(int n, int* rn) {
    pal* ls = (pal*) malloc(sizeof(pal) * (n+1));
    int i = 0, j = 0, k = 0, t = 0;
    ptn r = NULL, l = NULL, root = NULL, *ans = NULL;
    if (n == 0) {
        *rn = 0;
        return NULL;
    }
    for (i = 0; i <= n; i ++) ls[i] = L095_al_init(16);
    L095_al_add_last(ls[0], (ptn)NULL);
    for (j = 1; j <= n; j ++) {
        for (i = 0; i < j; i ++) {
            for (k = 0; k < ls[i]->size; k ++) {
                l = ls[i]->arr[k];
                for (t = 0; t < ls[j-1-i]->size; t ++) {
                    r = ls[j-1-i]->arr[t];
                    root = L095_tn_init(i+1);
                    root->left = L095_tn_copy_offset(l, 0);
                    root->right = L095_tn_copy_offset(r, i+1);
                    L095_al_add_last(ls[j], root);
                }
            }
        }
    }
    *rn = ls[n]->size;
    ans = (ptn*) malloc(sizeof(ptn) * ls[n]->size);
    for (i = 0; i < ls[n]->size; i ++) ans[i] = ls[n]->arr[i];
    for (i = 0; i <= n; i ++) L095_al_free(ls[i]);
    return ans;
}

int L095() {
    int n = 3;
    int rn = 0;
    ptn* a = L095_generateTrees(n, &rn);
    return 0;
}