/*
    url: leetcode.com/problems/validate-binary-search-tree
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define bool int
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


struct L098_TreeNode {
    int val;
    struct L098_TreeNode *left;
    struct L098_TreeNode *right;
};

bool L098_search(struct L098_TreeNode* root, long min, long max) {
    long v = 0;
    if (root == NULL) return 1;
    v = root->val;
    if (v < min || v > max) return 0;
    //printf("%ld %ld\n", min, max);
    return L098_search(root->left, min, min(max, v-1)) &&
            L098_search(root->right, max(min, v+1), max);
}

bool L098_isValidBST(struct L098_TreeNode* root) {
    return L098_search(root, INT_MIN, INT_MAX);
}