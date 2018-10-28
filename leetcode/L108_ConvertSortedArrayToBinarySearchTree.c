/*
    url: leetcode.com/problems/convert-sorted-array-to-binary-search-tree
    AC 6ms 36.54%
*/

#include <stdio.h>
#include <stdlib.h>

struct L108_TreeNode {
    int val;
    struct L108_TreeNode *left;
    struct L108_TreeNode *right;
};

typedef struct L108_TreeNode stn;
typedef struct L108_TreeNode * ptn;

ptn L108_tn_init(int val) {
    ptn n = (ptn) malloc(sizeof(stn));
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    return n;
}

ptn L108_search(int* n, int ni, int nj) {
    ptn root = NULL;
    int nm = (ni+nj)/2;
    if (ni > nj) return NULL;
    root = L108_tn_init(n[nm]);
    root->left = L108_search(n, ni, nm-1);
    root->right = L108_search(n, nm+1, nj);
    return root;
}

ptn L108_sortedArrayToBST(int* n, int nn) {
    return L108_search(n, 0, nn-1);
}