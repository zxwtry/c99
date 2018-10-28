/*
    url: leetcode.com/problems/remove-duplicates-from-sorted-list-ii
    AC 3ms 42.57%
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct L082_ListNode * pln;
typedef struct L082_ListNode sln;

struct L082_ListNode {
    int val;
    pln next;
};

pln L082_ln_construct(int val) {
    pln l = (pln) malloc(sizeof(sln));
    l->next = NULL;
    l->val = val;
    return l;
}

pln L082_deleteDuplicates(pln head) {
    pln h = NULL, t = NULL, tt = head;
    int pre_val = 0, cnt = 0;
    while (tt != NULL) {
        if (h == tt) {
            pre_val = tt->val;
            cnt = 1;
            tt = tt->next;
            continue;
        }
        if (pre_val == tt->val) {
            cnt ++;
            tt = tt->next;
            continue;
        }
        if (cnt == 1) {
            if (t == NULL) {
                h = t = L082_ln_construct(pre_val);
            } else {
                t->next = L082_ln_construct(pre_val);
                t = t->next;
            }
        }
        cnt = 1;
        pre_val = tt->val;
        tt = tt->next;
    }
    if (cnt == 1) {
        if (t == NULL) {
            h = t = L082_ln_construct(pre_val);
        } else {
            t->next = L082_ln_construct(pre_val);
            t = t->next;
        }
    }
    return h;
}