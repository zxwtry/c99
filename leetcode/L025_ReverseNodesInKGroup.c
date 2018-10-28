/*
    url: leetcode.com/problems/reverse-nodes-in-k-group/
    12ms 7.08%
*/

#include <stdio.h>
#include <stdlib.h>

struct L025_ListNode {
    int val;
    struct L025_ListNode *next;
};

struct L025_ListNode * L025_convert_int_to_ListNode(int * arr, int n) {
    struct L025_ListNode * head = NULL;
    struct L025_ListNode * travel = NULL;
    struct L025_ListNode * temp = NULL;
    int i = 0;
    if (n == 0 || n < 0) return NULL;
    travel = (struct L025_ListNode *) malloc(sizeof(struct L025_ListNode));
    travel->val = *(arr + 0);
    travel->next = NULL;
    head = travel;
    for (i = 1; i < n; i ++) {
        temp = (struct L025_ListNode *) malloc(sizeof(struct L025_ListNode));
        temp->val = *(arr + i);
        temp->next = NULL;
        travel->next = temp;
        travel = travel->next;
    }
    return head;
}

void L025_free_ListNode(struct L025_ListNode * l) {
    struct L025_ListNode * temp = NULL;
    while (l != NULL) {
        temp = l->next;
        free(l);
        l = temp;
    }
}

void L025_print_ListNode(struct L025_ListNode * h) {
    while (h != NULL) {
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\r\n");
}

struct L025_ListNode* L025_reverseKGroup(struct L025_ListNode* head, int k) {
    int i = 0;
    struct L025_ListNode * s = head, * t = NULL, * v = NULL, * pv = NULL;
    struct L025_ListNode * t1 = NULL, * t2 = NULL, * t0 = NULL;
    struct L025_ListNode * answer = head;
    if (k < 2 || head == NULL) return answer;
    while (s != NULL) {
        t = s;
        for (i = 1; i < k; i ++) {
            if (t == NULL) break;
            t = t->next;
        }
        if (pv != NULL) {
            pv->next = t == NULL ? s : t;
        }
        pv = s;
        if (t == NULL) break;
        if (answer == head) answer = t;
        v = t->next;

        t0 = s;
        t1 = t0->next;
        t2 = t1 != NULL ? t1->next : NULL;
        while (1) {
            t1->next = t0;
            if (t1 == t) break;
            t0 = t1;
            t1 = t2;
            t2 = t2 == NULL ? NULL : t2->next;
        }
        s = v;
    }
    if (s == NULL)
        pv->next = NULL;
    return answer;
}

int L025() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 11;
    struct L025_ListNode * head = L025_convert_int_to_ListNode(a, 10);
    struct L025_ListNode * answer = L025_reverseKGroup(head, k);
    L025_print_ListNode(answer);
    L025_free_ListNode(answer);
}