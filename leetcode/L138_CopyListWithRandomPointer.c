/*
    url: leetcode.com/problems/copy-list-with-random-pointer
    AC 26ms 8.30%
*/

#include <stdio.h>
#include <stdlib.h>

struct L138_RandomListNode {
    int label;
    struct L138_RandomListNode *next;
    struct L138_RandomListNode *random;
};

typedef struct L138_RandomListNode   sln;
typedef struct L138_RandomListNode * pln;

pln L138_copyRandomList(pln h) {
    pln t = h, n = NULL, c = NULL, ans = NULL;
    while (t != NULL) {
        n = t->next;

        c = (pln) malloc(sizeof(sln));
        c->label = t->label;
        c->next = t->next;
        t->next = c;
        
        
        t = n;
    }
    t = h;
    while (t != NULL) {
        n = t->next->next;

        c = t->next;
        if (t->random != NULL)
            c->random = t->random->next;
        else c->random = NULL;

        t = n;
    }
    t = h;
    ans = h == NULL ? NULL : h->next;
    while (t != NULL) {
        n = t->next->next;
    
        c = t->next;
        t->next = n;
        c->next = n == NULL ? NULL : n->next;
        
        t = n;
    }
    return ans;
}