/*
    url: leetcode.com/problems/binary-tree-inorder-traversal
    in_order:          AC 3ms 0.00%
    in_order_unrecur:  AC 0ms 62.86%
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct L094_TreeNode stn;
typedef struct L094_TreeNode * ptn;

typedef int T;
typedef struct L094_al sal;
typedef struct L094_al * pal;

struct L094_al {
    int capacity;
    int size;
    T* arr;
};

pal L094_al_init(int capacity) {
    pal l = (pal) malloc(sizeof(sal));
    if (capacity < 1) return NULL;
    l->arr = (T*) malloc(sizeof(T) * capacity);
    l->capacity = capacity;
    l->size = 0;
    return l;
}

void L094_al_expand_capacity(pal l) {
    T* new_arr = (T*) malloc(sizeof(T) * (l->capacity * 2 + 1));
    int i = 0;
    for (i = 0; i < l->capacity; i ++)
        new_arr[i] = l->arr[i];
    free(l->arr);
    l->arr = new_arr;
    l->capacity = l->capacity * 2 + 1;
}

void L094_al_add_last(pal l, T v) {
    if (l->capacity == l->size) L094_al_expand_capacity(l);
    l->arr[l->size] = v;
    l->size ++;
}

T* L094_al_convert_to_array_free_l(pal l) {
    T* arr = l->arr;
    free(l);
    return arr;
}

struct L094_TreeNode {
    int val;
    ptn left;
    ptn right;
};

void L094_in_order(ptn root, pal l) {
    if (root == NULL) return;
    L094_in_order(root->left, l);
    L094_al_add_last(l, root->val);
    L094_in_order(root->right, l);
}

//element type
typedef ptn V;
typedef struct L094_dll sdll;
typedef struct L094_dll * pdll;
typedef struct L094_dln sdln;
typedef struct L094_dln * pdln;


//doubly list node
struct L094_dln {
    V val;
    pdln pre;
    pdln nxt;
};

//doubly linked list
struct L094_dll {
    pdln first;
    pdln last;
    int size;
};

pdll L094_dll_init() {
    pdll l = (pdll) malloc(sizeof(sdll));
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
    return l;
}

void L094_dll_add_last(pdll l, V v) {
    pdln t = (pdln) malloc(sizeof(sdln));
    t->val = v;
    t->pre = NULL;
    t->nxt = NULL;
    if (l->size == 0) {
        l->first = t;
        l->last = t;
        l->size = 1;
        return;
    }
    t->pre = l->last;
    l->last->nxt = t;
    l->last = t;
    l->size ++;
}

void L094_dll_remove_last(pdll l) {
    pdln t = NULL;
    if (l->last == NULL) return;
    if (l->first == l->last) {
        free(l->first);
        l->first = NULL;
        l->last = NULL;
        l->size = 0;
        return;
    }
    t = l->last->pre;
    t->nxt = NULL;
    free(l->last);
    l->last = t;
    l->size --;
}

void L094_dll_free_all(pdll l) {
    pdln t1 = l->first, t2 = NULL;
    while (t1 != NULL) {
        t2 = t1->nxt;
        free(t1);
        t1 = t2;
    }
    free(l);
}

void L094_in_order_unrecur(ptn root, pal l) {
    pdll q = L094_dll_init();
    ptn now = root;
    while (1) {
        if (q->size == 0 && now == NULL) break;
        if (now == NULL) {
            now = q->last->val;
            L094_dll_remove_last(q);
            L094_al_add_last(l, now->val);
            now = now->right;
        } else {
            L094_dll_add_last(q, now);
            now = now->left;
        }
    }
    L094_dll_free_all(q);
}

int* L094_inorderTraversal(ptn root, int* rn) {
    pal l = L094_al_init(16);
    //in_order(root, l);
    L094_in_order_unrecur(root, l);
    *rn = l->size;
    return L094_al_convert_to_array_free_l(l);
}