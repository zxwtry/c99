/*
    url: leetcode.com/problems/sort-list
    sortList1: TLE
    sortList2: AC 23ms 34.00%
*/

#include <stdlib.h>

struct L148_ListNode {
    int val;
    struct L148_ListNode *next;
};

typedef struct L148_ListNode*  pln;
typedef struct L148_ListNode   sln;

int L148_cmp(pln n1, pln n2) {
    if (n1->val < n2->val) return -1;
    return n1->val > n2->val ? 1 : 0;
}

int L148_part(pln * ns, int i, int j) {
    pln s = ns[i];
    while (i < j) {
        while (i < j && L148_cmp(s, ns[j]) <= 0) j --;
        ns[i] = ns[j];
        while (i < j && L148_cmp(s, ns[i]) >= 0) i ++;
        ns[j] = ns[i];
    }
    ns[i] = s;
    return i;
}

void L148_quick_sort(pln * ns, int i, int j) {
    int m = 0;
    if (i < j) {
        m = L148_part(ns, i, j);
        L148_quick_sort(ns, i, m - 1);
        L148_quick_sort(ns, m + 1, j);
    }
}

pln L148_sortList1(pln head) {
    int len = 0;
    pln t = head;
    pln* ns = NULL;
    int index = 0;
    if (head == NULL) return NULL;
    while (t != NULL) {
        len ++;
        t = t->next;
    }
    t = head;
    ns = (pln *) malloc(sizeof(pln) * len);
    while (t != NULL) {
        ns[index ++] = t;
        t = t->next;
    }
    L148_quick_sort(ns, 0, len - 1);
    t = NULL;
    for (index = len - 1; index > -1; index --) {
        ns[index]->next = t;
        t = ns[index];
    }
    t = ns[0];
    free(ns);
    return t;
}


int L148_getLen(pln h) {
    int len = 0;
    while (h != NULL) {
        h = h->next;
        len ++;
    }
    return len;
}

pln L148_sortList2(pln h) {
    int len = L148_getLen(h);
    pln p = NULL, nn = NULL;
    pln ln = NULL, rn = NULL;
    int lc = 0, rc = 0;
    int le = 0, re = 0;
    int s = 0, si = 0;
    pln vh = (pln) malloc(sizeof(sln));
    vh->next = h;
    for (s = 1; s < len; s <<= 1) {
        ln = vh->next;
        rn = vh->next;
        lc = 0;
        rc = 0;
        p = vh;
        while (rn != NULL) {
            for (si = 0; si < s; si ++)
                rn = rn == NULL ? NULL : rn->next;
            if (rn == NULL) {
                p->next = ln;
                break;
            }
            lc = 0;
            rc = 0;
            while (lc < s || rc < s) {
                le = (ln == NULL || lc == s);
                re = (rn == NULL || rc == s);
                if (le || re) {
                    if (le && re) break;
                    if (le) {
                        nn = rn->next;
                        p->next = rn;
                        p = rn;
                        rn = rn->next;
                        rc ++;
                    } else {
                        p->next = ln;
                        p = ln;
                        ln = ln->next;
                        lc ++;
                    }
                } else {
                    if (ln->val > rn->val) {
                        nn = rn->next;
                        p->next = rn;
                        p = rn;
                        rn = rn->next;
                        rc ++;                    
                    } else {
                        p->next = ln;
                        p = ln;
                        ln = ln->next;
                        lc ++;
                    }
                }
            }
            p->next = NULL;
            ln = rn = nn;
        }
    }    
    //p as answer
    p = vh->next;
    free(vh);
    return p;
}