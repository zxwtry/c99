/*
    url: leetcode.com/problems/maximum-depth-of-binary-tree
    AC 3ms 75.91%
*/

#include "stdlib.h"

#define max(a, b) ((a) < (b) ? (a) : (b))

struct L104_TreeNode {
    int val;
    struct L104_TreeNode *left;
    struct L104_TreeNode *right;
};


void L104_search(struct L104_TreeNode* root, int cnt, int* ans) {
    if (root == NULL) {
        *ans = max(cnt, *ans);
    } else {
        L104_search(root->left, cnt+1, ans);
        L104_search(root->right, cnt+1, ans);
    }
}

int L104_maxDepth(struct L104_TreeNode* root) {
    int ans = 0;
    L104_search(root, 0, &ans);
    return ans;
}