/*
    url: leetcode.com/problems/same-tree
    AC 0ms 57.14%
*/

#include "stdlib.h"

struct L100_TreeNode {
    int val;
    struct L100_TreeNode *left;
    struct L100_TreeNode *right;
};

_Bool L100_isSameTree(struct L100_TreeNode* p, struct L100_TreeNode* q) {
    if (p == NULL || q == NULL)
        return p == NULL && q == NULL;
    if (p->val != q->val) return 0;
    return L100_isSameTree(p->left, q->left) &&
            L100_isSameTree(p->right, q->right);
}