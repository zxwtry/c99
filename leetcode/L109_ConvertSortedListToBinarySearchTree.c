/*
*/

#include <stdio.h>
#include <stdlib.h>

struct L109_ListNode {
    int val;
    struct L109_ListNode *next;
};


struct L109_TreeNode {
    int val;
    struct L109_TreeNode *left;
    struct L109_TreeNode *right;
};

typedef struct L109_ListNode sln;
typedef struct L109_ListNode * pln;
typedef struct L109_TreeNode stn;
typedef struct L109_TreeNode * ptn;

ptn L109_search(int* a, int ai, int aj) {
    int am = (ai + aj + 1) / 2;
    ptn n = NULL;
    if (ai > aj) return NULL;
    n = (ptn) malloc(sizeof(stn));
    n->left = L109_search(a, ai, am-1);
    n->right = L109_search(a, am+1, aj);
    n->val = a[am];
    return n;
}

ptn L109_sortedListToBST(pln h) {
    int hn = 0, *a = NULL, i = 0;
    pln t = h;
    ptn ans = NULL;
    while (t != NULL) {
        t = t->next;
        hn ++;
    }
    a = (int*) malloc(sizeof(int) * hn);
    t = h;
    while (t != NULL) {
        a[i] = t->val;
        t = t->next;
        i ++;
    }
    ans = L109_search(a, 0, hn-1);
    free(a);
    return ans;
}