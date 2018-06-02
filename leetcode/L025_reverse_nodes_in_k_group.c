//
// Created by zxwtry on 2018/6/2.
//


#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode * next;
};



struct ListNode * L025_construct_array(int* array, int size) {
    struct ListNode * cur = NULL;
    struct ListNode * pre = NULL;
    int index = size - 1;
    for (; index > -1; index --) {
        cur = (struct ListNode *) malloc(sizeof(struct ListNode));
        cur->val = array[index];
        cur->next = pre;
        pre = cur;
    }
    return cur;
}


void L025_print(struct ListNode * head) {
    int index = 0;
    while (head != NULL) {
        printf("%d\t\t%d\n", index ++, head->val);
        head = head->next;
    }
}


void L025_free(struct ListNode * head) {
    struct ListNode * nxt = NULL;
    int freeTimes = 0;
    while (head != NULL) {
        nxt = head->next;
        free(head);
        freeTimes ++;
        head = nxt;
    }
    printf("free times is %d\n", freeTimes);
}


// AC 4ms 100.00 %
struct ListNode* L025_reverseKGroup(struct ListNode* head, int k) {
    struct ListNode * groupHead = head;
    struct ListNode * groupTail = NULL;
    struct ListNode * preTail = NULL;
    struct ListNode * nxtHead = NULL;
    struct ListNode * reversePre = NULL;
    struct ListNode * reverseNxt = NULL;
    struct ListNode * tmp = NULL;
    struct ListNode * ans = NULL;

    int ki = 0;

    while (1) {
        tmp = groupHead;
        for (ki = 0; ki + 1 < k && tmp != NULL; ++ki) {
            tmp = tmp->next;
        }
        if (tmp == NULL) {
            if (ans == NULL) {
                ans = groupHead;
            } else {
                preTail->next = groupHead;
            }
            break;
        }
        groupTail = tmp;
        if (ans == NULL) {
            ans = groupTail;
        }
        nxtHead = tmp->next;
        reverseNxt = groupHead;
        reversePre = NULL;
        for (ki = 0; ki < k; ++ki) {
            tmp = reverseNxt;
            reverseNxt = tmp->next;
            tmp->next = reversePre;
            reversePre = tmp;
        }
        if (preTail != NULL) {
            preTail->next = groupTail;
        }
        preTail = groupHead;
        groupHead = nxtHead;
    }
    return ans;
}


void L025() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9;
    struct ListNode * head = L025_construct_array(array, size);
    struct ListNode * ans = L025_reverseKGroup(head, 10);
    L025_print(ans);
    L025_free(head);
}