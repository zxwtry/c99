/*
    url: leetcode.com/problems/swap-nodes-in-pairs/
    6ms 0.0%
*/

#include <stdio.h>
#include <stdlib.h>

struct L024_ListNode {
    int val;
    struct L024_ListNode *next;
};

struct L024_ListNode * convert_int_to_ListNode(int * arr, int n) {
    struct L024_ListNode * head = NULL;
    struct L024_ListNode * travel = NULL;
    struct L024_ListNode * temp = NULL;
    int i = 0;
    if (n == 0 || n < 0) return NULL;
    travel = (struct L024_ListNode *) malloc(sizeof(struct L024_ListNode));
    travel->val = *(arr + 0);
    travel->next = NULL;
    head = travel;
    for (i = 1; i < n; i ++) {
        temp = (struct L024_ListNode *) malloc(sizeof(struct L024_ListNode));
        temp->val = *(arr + i);
        temp->next = NULL;
        travel->next = temp;
        travel = travel->next;
    }
    return head;
}

void L024_free_ListNode(struct L024_ListNode * l) {
    struct L024_ListNode * temp = NULL;
    while (l != NULL) {
        temp = l->next;
        free(l);
        l = temp;
    }
}

void L024_print_ListNode(struct L024_ListNode * h) {
    while (h != NULL) {
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\r\n");
}

struct L024_ListNode* L024_swapPairs(struct L024_ListNode* head) {
    struct L024_ListNode * t1 = head, * t2 = NULL, * t3 = NULL, * t0 = NULL;
    struct L024_ListNode * answer = head;
    t2 = t1 == NULL ? NULL : t1->next;
    t3 = t2 == NULL ? NULL : t2->next;
    while (t2 != NULL) {
        t2->next = t1;
        if (t0 != NULL)
            t0->next = t2;
        if (head == answer)
            answer = t2;
        t0 = t1;
        t1 = t3;
        t2 = t1 == NULL ? NULL : t1->next;
        t3 = t2 == NULL ? NULL : t2->next;
    }
    if (t0 != NULL)
        t0->next = t1;
    return answer;
}

int L024() {
    int a[] = {1};
    struct L024_ListNode * l = convert_int_to_ListNode(a, 1);
    struct L024_ListNode * answer = L024_swapPairs(l);
    L024_print_ListNode(answer);
    L024_free_ListNode(answer);
}