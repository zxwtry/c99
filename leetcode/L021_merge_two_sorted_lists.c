//
// Created by zxwtry on 2018/5/30.
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


struct ListNode * L021_construct_array(int * arr, int size) {
    struct ListNode * pre = NULL;
    struct ListNode * cur = NULL;
    int index = 0;
    for (index = size - 1; index > -1; --index) {
        cur = (struct ListNode *) malloc(sizeof(struct ListNode));
        cur->val = arr[index];
        cur->next = pre;
        pre = cur;
    }
    return cur;
}


void L021_print(struct ListNode * head) {
    int index = 0;
    while (head != NULL) {
        printf("index:%d\t\tvalue:%d\n", index ++, head->val);
        head = head->next;
    }
}


// AC 8ms 45.82 %
struct ListNode* L021_mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * t1 = l1;
    struct ListNode * t2 = l2;
    struct ListNode * t = l1;
    if (l1 == NULL || l2 == NULL) {
        return l1 == NULL ? l2 : l1;
    }
    if (l1->val > l2->val) {
        return L021_mergeTwoLists(l2, l1);
    }
    t1 = t1->next;
    while (t1 != NULL && t2 != NULL) {
        if (t1->val < t2->val) {
            t->next = t1;
            t1 = t1->next;
            t = t->next;
        } else {
            t->next = t2;
            t2 = t2->next;
            t = t->next;
        }
    }
    if (t1 == NULL) {
        t->next = t2;
    } else {
        t->next = t1;
    }
    return l1;
}

void L021() {
    int arr1 [] = {1, 3, 5, 7};
    int size1 = 4;
    int arr2 [] = {5};
    int size2 = 1;
    struct ListNode * head1 = L021_construct_array(arr1, size1);
    struct ListNode * head2 = L021_construct_array(arr2, size2);
    struct ListNode * ans = L021_mergeTwoLists(head1, head2);
    L021_print(ans);
}