//
// Created by zxwtry on 2018/5/29.
//

#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * L019_construct_from_array(int * arr, int size) {
    struct ListNode * cur = NULL;
    struct ListNode * pre = NULL;
    int index = 0;
    for (index = size - 1; index > -1; --index) {
        cur = (struct ListNode *) malloc(sizeof(struct ListNode));
        cur->next = NULL;
        cur->val = arr[index];
        cur->next = pre;
        pre = cur;
    }
    return cur;
}

void L019_print_ListNode(struct ListNode * head) {
    int index = 0;
    while (head != NULL) {
        printf("index:%d\t\tvalue:%d\n", index ++, head->val);
        head = head->next;
    }
}


// AC 4ms 100.00 %
struct ListNode* L019_removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode * p1 = head, * p2 = head;
    int i = 0;
    while (p1 != NULL && i ++ < n) {
        p1 = p1->next;
    }
    if (p1 == NULL) {
        if (i == n) {
            return head == NULL ? NULL : head->next;
        }
        return head;
    }
    while (p1->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p2->next != NULL) {
        p2->next = p2->next->next;
    }
    return head;
}

void L019() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    struct ListNode * lst_arr = L019_construct_from_array(arr, size);
    struct ListNode * ans = L019_removeNthFromEnd(lst_arr, 6);
    L019_print_ListNode(ans);
}