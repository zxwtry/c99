/*
    url: leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
    AC 19ms 6.25%
*/

#include <stdio.h>
#include <stdlib.h>

struct L106_TreeNode {
    int val;
    struct L106_TreeNode *left;
    struct L106_TreeNode *right;
};


typedef struct L106_TreeNode stn;
typedef struct L106_TreeNode * ptn;

ptn L106_tn_init(int val) {
    ptn n = (ptn) malloc(sizeof(stn));
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    return n;
}

ptn L106_search(int* i, int ii, int ij, int* p, int pi, int pj) {
    int lt = 0, rt = 0;
    ptn n = NULL;
    if (ii > ij) return NULL;
    while (i[ii+lt] != p[pj]) lt ++;
    rt = ij - ii - lt;
    n = L106_tn_init(p[pj]);
    n->left = L106_search(i, ii, ii+lt-1, p, pi, pi+lt-1);
    n->right = L106_search(i, ij-rt+1, ij, p, pj-rt, pj-1);
    return n;
}

ptn L106_buildTree(int* i, int in, int* p, int pn) {
    return L106_search(i, 0, in-1, p, 0, pn-1);
}