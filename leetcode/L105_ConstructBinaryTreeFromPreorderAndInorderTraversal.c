/*
    url: leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
    AC 13ms 14.29%
*/

#include <stdio.h>
#include <stdlib.h>

struct L105_TreeNode {
    int val;
    struct L105_TreeNode *left;
    struct L105_TreeNode *right;
};

typedef struct L105_TreeNode stn;
typedef struct L105_TreeNode * ptn;

ptn L105_tn_init(int val) {
    ptn t = (ptn) malloc(sizeof(stn));
    t->val = val;
    t->left = NULL;
    t->right = NULL;
    return t;
}

ptn L105_search(int* p, int pi, int pj, int* i, int ii, int ij) {
    int lt = 0, rt = 0;
    ptn n = NULL;
    if (pi > pj) return NULL;
    while(i[ii+lt] != p[pi]) lt ++;
    rt = pj-pi-lt;
    n = L105_tn_init(p[pi]);
    n->left = L105_search(p, pi+1, pi+lt, i, ii, ii+lt-1);
    n->right = L105_search(p, pj-rt+1, pj, i, ij-rt+1, ij);
    return n;
}

ptn L105_buildTree(int* p, int pn, int* i, int in) {
    return L105_search(p, 0, pn-1, i, 0, in-1);
}