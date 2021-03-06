/*
    url: leetcode.com/problems/reverse-linked-list-ii
    AC 0ms 73.39%
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct L092_ListNode sln;
typedef struct L092_ListNode * pln;

struct L092_ListNode {
    int val;
    struct L092_ListNode * next;
};

pln L092_convert_int_to_ListNode(int * arr, int n) {
    pln head = NULL;
    pln travel = NULL;
    pln temp = NULL;
    int i = 0;  
    if (n == 0 || n < 0) return NULL;
    travel = (pln) malloc(sizeof(sln));
    travel->val = *(arr + 0);
    travel->next = NULL;
    head = travel;
    for (i = 1; i < n; i ++) {
        temp = (pln) malloc(sizeof(sln));
        temp->val = *(arr + i);
        temp->next = NULL;
        travel->next = temp;
        travel = travel->next;
    }
    return head;
}

void L092_free_ListNode(struct L092_ListNode * l) {
    struct L092_ListNode * l1 = l, * l2 = l;
    if (l == NULL) return;
    while (l1 != NULL) {
        l2 = l2->next;
        free(l1);
        l1 = l2;
    }
}

void L092_print_ListNode(pln l) {
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\r\n");
}

pln L092_reverseBetween(pln h, int m, int n) {
    int i = 1;
    pln t = h, s = NULL, p = NULL;
    pln h1 = NULL, h2 = NULL;
    pln e1 = NULL, e2 = NULL;
    while (t != NULL) {
        s = t->next;
        if (i == m-1) e1 = t;
        if (i == n+1) {
            e2 = t;
            break;
        }
        if (i == m) h1 = t;
        if (i == n) h2 = t;
        if (i > m && i <= n) {
            t->next = p;
        }
        p = t;
        t = s;
        i ++;
    }
    if (e1 != NULL) e1->next = h2;
    if (h1 != NULL) h1->next = e2;
    return m == 1 ? h2 : h;
}

int L092() {
    /*
        1, 2, 3, 4, 5, 6, 7, 8, 9
        1, 2
        1, 1
        2, 4

    */
    int a[] = {1};
    pln h = L092_convert_int_to_ListNode(a, 1);
    pln ans = L092_reverseBetween(h, 1, 1);
    L092_print_ListNode(ans);
    return 0;
    
}