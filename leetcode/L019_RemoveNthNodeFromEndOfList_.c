/*
    url: leetcode.com/problems/remove-nth-node-from-end-of-list/
    6ms 19.31%
*/

#include <stdlib.h>
#include <stdio.h>

struct L019_ListNode {
    int val;
    struct L019_ListNode *next;
};

//all head and n is valid
struct ListNode* L019_removeNthFromEnd(struct L019_ListNode* head, int n) {
    struct L019_ListNode * front = head, * tail = head;
    int i = 0;
    for (i = 0; i < n; i ++) {
        front = front->next;
    }
    if (front == NULL) return head->next;
    front = front->next;
    while (front != NULL) {
        front = front->next;
        tail = tail->next;
    }
    tail->next = tail->next->next;
    return head;
}

struct L019_ListNode * L019_convert_int_to_ListNode(int * arr, int n) {
    struct L019_ListNode * head = NULL;
    struct L019_ListNode * travel = NULL;
    struct L019_ListNode * temp = NULL;
    int i = 0;
    if (n == 0 || n < 0) return NULL;
    travel = (struct L019_ListNode *) malloc(sizeof(struct L019_ListNode));
    travel->val = *(arr + 0);
    travel->next = NULL;
    head = travel;
    for (i = 1; i < n; i ++) {
        temp = (struct L019_ListNode *) malloc(sizeof(struct L019_ListNode));
        temp->val = *(arr + i);
        temp->next = NULL;
        travel->next = temp;
        travel = travel->next;
    }
    return head;
}

void L019_free_ListNode(struct L019_ListNode * l) {
    struct L019_ListNode * l1 = l, * l2 = l;
    if (l == NULL) return;
    while (l1 != NULL) {
        l2 = l2->next;
        free(l1);
        l1 = l2;
    }
}

void L019_print_ListNode(struct L019_ListNode * h) {
    while (h != NULL) {
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\r\n");
}

int L019() {
    int a[] = {1, 2, 3, 4, 5};
    struct L019_ListNode * head = L019_convert_int_to_ListNode(a, 5);
    struct L019_ListNode * answer = L019_removeNthFromEnd(head, 2);
    L019_print_ListNode(answer);
}