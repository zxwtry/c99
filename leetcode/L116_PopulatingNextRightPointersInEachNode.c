/*
    url: leetcode.com/problems/populating-next-right-pointers-in-each-node
    AC 12ms 12.50%
*/
#include "stdlib.h"

struct L116_TreeLinkNode {
    int val;
    struct L116_TreeLinkNode *left, *right, *next;
};

typedef struct L116_TreeLinkNode * ptln;

void L116_connect(ptln root) {
    ptln ll = root, p = NULL, pl = root;
    if (root == NULL) return;
    root->next = NULL;
    while (pl != NULL) {
        ll = pl;
        pl = NULL;
        p = NULL;
        while (ll != NULL) {
            if (ll->left != NULL) {
                if (p == NULL) {
                    pl = p = ll->left;
                } else {
                    p->next = ll->left;
                    p = p->next;
                }
            }
            if (ll->right != NULL) {
                if (p == NULL) {
                    pl = p = ll->right;
                } else {
                    p->next = ll->right;
                    p = p->next;
                }
            }
            ll = ll->next;
        }
    }
}