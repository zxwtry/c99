//
// Created by zxwtry on 2018/6/1.
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


struct ListNode * L023_constrct_from_array(int * array, int size) {
    int index = 0;
    struct ListNode * cur = NULL;
    struct ListNode * pre = NULL;
    for (index = size - 1; index > -1; --index) {
        cur = (struct ListNode *) malloc(sizeof(struct ListNode));
        cur->val = array[index];
        cur->next = pre;
        pre = cur;
    }
    return cur;
}

void L023_print(struct ListNode * head) {
    int index = 0;
    while (head != NULL) {
        printf("%d\t\t%d\n", index ++, head->val);
        head = head->next;
    }
}

// AC 256ms 33.12 %
struct ListNode* L023_mergeKLists(struct ListNode** lists, int listsSize) {
    int listsIndex = 0;
    struct ListNode * ans = NULL;
    struct ListNode * tra = NULL;
    int listsSelIndex;
    int listsSelValue;
    while (1) {
        listsSelIndex = -1;
        listsSelValue = INT_MAX;
        for (listsIndex = 0; listsIndex < listsSize; ++listsIndex) {
            if (lists[listsIndex] != NULL && lists[listsIndex]->val <= listsSelValue) {
                listsSelIndex = listsIndex;
                listsSelValue = lists[listsIndex]->val;
            }
        }
        if (listsSelIndex == -1) {
            break;
        } else {
            if (ans == NULL) {
                ans = lists[listsSelIndex];
                tra = ans;
            } else {
                tra->next = lists[listsSelIndex];
                tra = tra->next;
            }
            lists[listsSelIndex] = lists[listsSelIndex]->next;
        }
    }
    return ans;
}


int L023_02_compare(struct ListNode * l1, struct ListNode * l2) {
    if (l1 == l2) {
        return 0;
    } else if (l1 == NULL || l2 == NULL) {
        return l1 == NULL ? -1 : 1;
    }
    return l1->val < l2->val ? -1 : 1;
}


void L023_02_swap(struct ListNode ** lists, int i, int j) {
    struct ListNode * tmp = lists[i];
    lists[i] = lists[j];
    lists[j] = tmp;
}

void L023_02_heapDown(struct ListNode ** lists, int index, int listsSize) {
    int left = 2 * index + 1;
    int right = left + 1;
    int selIndex = index;
    if (left < listsSize && L023_02_compare(lists[selIndex], lists[left]) > 0) {
        selIndex = left;
    }
    if (right < listsSize)



}


struct ListNode* L023_02_mergeKLists(struct ListNode** lists, int listsSize) {

}


void L023() {
    struct ListNode ** input = (struct ListNode **) malloc(sizeof(struct ListNode *) * 3);
    int arr1[] = {1, 4, 7, 10};
    int arr2[] = {2, 5, 9, 11};
    int arr3[] = {3, 8, 10, 18};
    struct ListNode * ans = NULL;
    input[0] = L023_constrct_from_array(arr1, 4);
    input[1] = L023_constrct_from_array(arr2, 4);
    input[2] = L023_constrct_from_array(arr3, 4);
    //L023_print(input[2]);
    ans = L023_mergeKLists(input, 3);
    L023_print(ans);
}