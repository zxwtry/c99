/*
    url: leetcode.com/problems/recover-binary-search-tree
    both: AC 12ms 100.00%
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct L099_TreeNode stn;
typedef struct L099_TreeNode * ptn;

struct L099_TreeNode {
    int val;
    struct L099_TreeNode *left;
    struct L099_TreeNode *right;
};

typedef ptn T;
typedef struct L099_al sal;
typedef struct L099_al * pal;

struct L099_al {
    int capacity;
    int size;
    T* arr;
};

pal L099_al_init(int capacity) {
    pal l = (pal) malloc(sizeof(sal));
    if (capacity < 1) return NULL;
    l->arr = (T*) malloc(sizeof(T) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L099_al_expand_capacity(pal l) {
    T* new_arr = (T*) malloc(sizeof(T) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L099_al_add_last(pal l, T v) {
    if (l->capacity == l->size) L099_al_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

T* L099_al_convert_to_array_free_l(pal l) {
    T* arr = l->arr;
    free(l);
    return arr;
}

void L099_pre_order(pal l, ptn root) {
    if (root == NULL) return;
    L099_pre_order(l, root->left);
    L099_al_add_last(l, root);
    L099_pre_order(l, root->right);
}

void L099_swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void L099_recoverTree_n(ptn root) {
    int i = 0, c = 0;
    pal l = L099_al_init(16);
    int w1 = 0, w2 = 0;
    int size = 0;
    ptn * arr = NULL;
    L099_pre_order(l, root);
    size = l->size;
    arr = L099_al_convert_to_array_free_l(l);
    for (i = 1; i < size; i ++) {
        if (arr[i]->val < arr[i-1]->val) {
            if (c == 0) {
                w1 = i;
                c ++;
            } else if (c == 1) {
                w2 = i;
                c ++;
            }
        }
    }
    if (c == 2) {
        L099_swap(&(arr[w1-1]->val), &(arr[w2]->val));
    }
    if (c == 1) {
        L099_swap(&(arr[w1]->val), &(arr[w1-1]->val));
    }
}

void L099_pre_order_1(ptn root, ptn* p, ptn* ps) {
    if (root == NULL) return;
    L099_pre_order_1(root->left, p, ps);
    if (*p != NULL)
    if (root->val <= (*p)->val) {
        if (ps[0] == NULL) {
            ps[0] = *p;
        }
        ps[1] = root;
    }
    *p = root;
    L099_pre_order_1(root->right, p, ps);
}

void L099_recoverTree_1(ptn root) {
    ptn p = NULL;
    ptn ps[2] = {NULL, NULL};
    L099_pre_order_1(root, &p, ps);
    L099_swap(&(ps[0]->val), &(ps[1]->val));
}

void L099_recoverTree(ptn root) {
    L099_recoverTree_n(root);
}



