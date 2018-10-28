/*
    url: leetcode.com/problems/insertion-sort-list
    AC 42ms  54.72%
*/

#include <stdio.h>
#include <stdlib.h>



struct L147_ListNode {
    int val;
    struct L147_ListNode *next;
};

typedef struct L147_ListNode * pln;

typedef struct L147_ListNode   sln;


pln L147_insertionSortList(pln h) {
    pln h1 = NULL, h2 = h;
    pln tt = NULL, tp = NULL;
    pln t = NULL;
    
    while (h2 != NULL) {
        t = h2;
        h2 = h2->next;

        if (h1 == NULL) {
            h1 = t;
            continue;
        }

        tt = h1;
        tp = NULL;
        
        while (tt != NULL && tt->val < t->val) {
            tp = tt;
            tt = tt->next;
        }

        if (tp == NULL) {
            t->next = h1;
            h1 = t;
        } else {
            t->next = tp->next;
            tp->next = t;
        }

    }

    
    return h1;

}