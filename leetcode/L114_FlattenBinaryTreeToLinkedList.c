/*
    url: leetcode.com/problems/flatten-binary-tree-to-linked-list
    search: AC 6ms 12.50%
    solve:  AC 3ms 42.50%
*/

#include <stdio.h>
#include <stdlib.h>

struct L114_TreeNode {
    int val;
    struct L114_TreeNode *left;
    struct L114_TreeNode *right;
};

typedef struct L114_TreeNode stn;
typedef struct L114_TreeNode * ptn;

void L114_search(ptn root, ptn* pre) {
    if (root == NULL) return;
    L114_search(root->right, pre);
    L114_search(root->left, pre);
    root->right = *pre;
    *pre = root;
    root->left = NULL;
}

void L114_solve(ptn root) {
    ptn n = root, p = NULL;
    while (n != NULL) {
        if (n->left != NULL) {
            p = n->left;
            while (p->right != NULL)
                p = p->right;
            p->right = n->right;
            n->right = n->left;
            n->left = NULL;
        }
        n = n->right;
    }
}


void L114_flatten(ptn root) {
    //ptn pre = NULL;
    //search(root, &pre);
    L114_solve(root);
}