/*
    url: leetcode.com/problems/remove-duplicates-from-sorted-list
    AC 6ms 9.62%
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct L083_ListNode * pln;
typedef struct L083_ListNode sln;

struct L083_ListNode {
    int val;
    struct L083_ListNode *next;
};

pln L083_deleteDuplicates(pln h) {
    pln p = NULL, n = h;
    while (n != NULL) {
        if (p == NULL) {
            p = n;
        } else {
            if (p->val != n->val) {
                p->next = n;
                p = n;
            }
        }
        n = n->next;
    }
    if (p != NULL) p->next = NULL;
    return h;
}
