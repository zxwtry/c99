/*
    url: leetcode.com/problems/partition-list
    AC 3ms 19.74%
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct L086_ListNode * pln;
typedef struct L086_ListNode sln;

struct L086_ListNode {
    int val;
    struct L086_ListNode *next;
};

void L086_solve(pln* sh, pln* st, pln* t) {
    if (*sh == NULL) {
        *sh = *st = *t;
    } else {
        (*st)->next = *t;
        *st = *t;
    }
}

pln L086_partition(pln head, int x) {
    pln sh = NULL, bh = NULL;
    pln st = NULL, bt = NULL;
    pln t = head;
    while (t != NULL) {
        if (t->val < x) {
            L086_solve(&sh, &st, &t);
        } else {
            L086_solve(&bh, &bt, &t);
        }
        t = t->next;
    }
    if (sh == NULL) return bh;
    if (bh == NULL) return sh;
    st->next = bh;
    bt->next = NULL;
    return sh;
}

pln L086_ln_construct(int* a, int n) {
    pln* l = (pln*) malloc(sizeof(pln) * n);
    int i = 0;
    pln ans = NULL;
    for (i = n-1; i > -1; i --) {
        l[i] = (pln) malloc(sizeof(sln));
        l[i]->next = i == n-1 ? NULL: l[i+1];
        l[i]->val = a[i];
    }
    if (n-1 > -1)
        l[n-1]->next = NULL;
    ans = l[0];
    free(l);
    return ans;
}

void L086_ln_print(pln l) {
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\r\n");
}

void L086_ln_free(pln l) {
    pln i = l, j = NULL;
    while(i != NULL) {
        j = i->next;
        free(i);
        i = j;
    }
}

int L086() {
    int n[] ={1,4,3,2,5,2};
    pln l = L086_ln_construct(n, 6);
    pln a = L086_partition(l, 3);
    L086_ln_print(a);
    L086_ln_free(l);
}