/*
    url: leetcode.com/problems/sum-root-to-leaf-numbers
    AC 3ms 0.00%
*/

#include <stdio.h>
#include <stdlib.h>

struct L129_TreeNode {
    int val;
    struct L129_TreeNode *left;
    struct L129_TreeNode *right;
};

void L129_search(struct L129_TreeNode* root, int * sum, int t) {
    int l = 0, r = 0;
    if (root == NULL) return;
    t = t*10+root->val;
    L129_search(root->left, sum, t);
    L129_search(root->right, sum, t);
    if (root->left == NULL && root->right == NULL) 
        *sum += t;
}

int L129_sumNumbers(struct L129_TreeNode* root) {
    int sum = 0;
    L129_search(root, &sum, 0);
    return sum;
}