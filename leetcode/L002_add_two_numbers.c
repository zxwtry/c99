//
// Created by zxwtry on 2018/5/14.
//


#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 *  这里碰到一个问题
 *  节点初始化：
 *   struct ListNode * p = (struct ListNode *) malloc(sizeof(struct ListNode))
 *   而不是：
 *   struct ListNode * p = (struct ListNode *) malloc(sizeof(struct ListNode *))
 *
 *   下面这个在某些平台上面会出现如下错误：
 *   store to address 0x000000ded278 with insufficient space for an object of type 'struct ListNode *'
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

int getLengthOfNode(struct ListNode * l) {
    int len = 0;
    while (l != NULL) {
        len ++;
        l = l->next;
    }
    return len;
}

struct ListNode * constrct(int* arr, int len) {
    struct ListNode * head = NULL;
    struct ListNode * t = NULL;
    struct ListNode * p = NULL;
    for (int i = 0; i < len; ++i) {
        t = (struct ListNode *) malloc(sizeof(struct ListNode));
        t->val = arr[i];
        t->next = NULL;
        if (head == NULL) {
            head = t;
        }
        if (p != NULL) {
            p->next = t;
        }
        p = t;
    }
    return head;
}


void printList(struct ListNode * l) {
    int index = 0;
    while (l != NULL) {
        printf("index:%d  value:%d\n", index ++, l->val);
        l = l->next;
    }
}

void freeList(struct ListNode * l) {
    struct ListNode * t = NULL;
    while (l != NULL) {
        t = l->next;
        free(l);
        l = t;
    }
}

struct ListNode* addTwoNode(struct ListNode * n1, struct ListNode * n2) {
    return NULL;
}

struct ListNode* L002_addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int n1 = getLengthOfNode(l1);
    int n2 = getLengthOfNode(l2);
    if (n1 < n2) {
        return addTwoNumbers(l2, l1);
    }
    struct ListNode * t1 = l1;
    struct ListNode * t2 = l2;
    struct ListNode * t1p = NULL;
    int carry = 0;
    while (t1 != NULL) {
        carry += t1->val;
        if (t2 != NULL) {
            carry += t2->val;
        }
        t1->val = carry % 10;
        carry = carry / 10;
        t1p = t1;
        t1 = t1->next;
        if (t2 != NULL) {
            t2 = t2->next;
        }
    }
    struct ListNode *t = NULL;
    while (carry != 0) {
        t = (struct ListNode *) malloc(sizeof(struct ListNode));
        t->next = NULL;
        t->val = carry % 10;
        carry = carry / 10;
        t1p->next = t;
        t1p = t;
    }
    return l1;
}


void L002() {
    int a1[] = {5};
    int a2[] = {5};
    int n1 = 1;
    int n2 = 1;
    struct ListNode * l1 = constrct(a1, n1);
    struct ListNode * l2 = constrct(a2, n2);
    struct ListNode * ans = L002_addTwoNumbers(l1, l2);

    printList(l1);
    printList(l2);
    printList(ans);




}