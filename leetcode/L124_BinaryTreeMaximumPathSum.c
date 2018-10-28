/*
    url: leetcode.com/problems/binary-tree-maximum-path-sum
    AC 15ms 59.26%
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

struct L124_TreeNode {
    int val;
    struct L124_TreeNode *left;
    struct L124_TreeNode *right;
};

typedef struct L124_TreeNode stn;
typedef struct L124_TreeNode * ptn;

int L124_search(ptn n, int* m) {
    int lv = 0, rv = 0;
    if (n == NULL) return 0;
    lv = L124_search(n->left, m);
    rv = L124_search(n->right, m);
    *m = max(*m, lv + rv + n->val);
    return max(max(max(lv, rv), 0) + n->val, 0);
}

int L124_maxPathSum(ptn n) {
    int m = INT_MIN;
    if (n == NULL) return 0;
    L124_search(n, &m);
    return m;
}