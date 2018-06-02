//
// Created by zxwtry on 2018/6/2.
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
    struct ListNode * next;
};


struct ListNode * L024_constrcut_from_array(int * array, int size) {
    struct ListNode * ans = NULL;
    struct ListNode * pre = NULL;
    int index;
    for (index = size - 1; index > -1; --index) {
        ans = (struct ListNode *) malloc(sizeof(struct ListNode));
        ans->next = pre;
        ans->val = array[index];
        pre = ans;
    }
    return ans;
}


void L024_print(struct ListNode * head) {
    int index = 0;
    while (head != NULL) {
        printf("%d\t\t%d\n", index ++, head->val);
        head = head->next;
    }
}


// AC 0ms 100.00 %
struct ListNode* L024_swapPairs(struct ListNode* head) {

    int k = 2;
    struct ListNode * ans = NULL;
    struct ListNode * segHead = head;
    struct ListNode * segTail = NULL;
    struct ListNode * segTemp = NULL;
    struct ListNode * nxtHead = NULL;
    struct ListNode * preTail = NULL;
    struct ListNode * reversePre = NULL;
    struct ListNode * reverseNxt = NULL;
    int ki;

    while (1) {
        segTemp = segHead;
        for (ki = 0; ki < k - 1 && segTemp != NULL; ++ki) {
            segTemp = segTemp->next;
        }
        if (segTemp == NULL) {
            if (ans == NULL) {
                ans = segHead;
            } else {
                preTail->next = segHead;
            }
            break;
        }
        nxtHead = segTemp->next;
        segTail = segTemp;
        // 从segHead到segTail反转
        reversePre = NULL;
        reverseNxt = segHead;
        for (ki = 0; ki < k; ++ki) {
            segTemp = reverseNxt;
            reverseNxt = segTemp->next;
            segTemp->next = reversePre;
            reversePre = segTemp;
        }
        if (preTail != NULL) {
            preTail->next = segTail;
        }
        if (ans == NULL) {
            ans = segTail;
        }
        preTail = segHead;
        segHead = nxtHead;
    }
    return ans;
}


void L024() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9;
    struct ListNode * head = L024_constrcut_from_array(array, size);
    struct ListNode * ans = L024_swapPairs(head);
    L024_print(ans);
}