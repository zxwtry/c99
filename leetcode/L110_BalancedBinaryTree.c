/*
    url: leetcode.com/problems/balanced-binary-tree
    AC 6ms 54.31%
*/

#include <stdio.h>
#include <stdlib.h>

struct L010_TreeNode {
    int val;
    struct L010_TreeNode *left;
    struct L010_TreeNode *right;
};

#define bool int

typedef struct L010_TreeNode stn;
typedef struct L010_TreeNode * ptn;


int L010_search(ptn root, int* b) {
    int cut = 0, lc = 0, rc = 0;
    if (root == NULL) return 0;
    lc = L010_search(root->left, b);
    if (! (*b)) return 0;
    rc = L010_search(root->right, b);
    cut = lc - rc;
    if (cut < -1 || cut > 1) *b = 0;
    if (! (*b)) return 0;
    return lc > rc ? lc+1 : rc+1;
}

bool L010_isBalanced(ptn root) {
    int cut = 0, lc = 0, rc = 0, b = 1;
    if (root == NULL) return 1;
    lc = L010_search(root->left, &b);
    if (! b) return 0;
    rc = L010_search(root->right, &b);
    if (! b) return 0;
    cut = lc - rc;
    return cut >= -1 && cut <= 1;
}