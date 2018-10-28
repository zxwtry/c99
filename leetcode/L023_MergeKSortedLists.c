/*
    url: leetcode.com/problems/merge-k-sorted-lists/
    12ms 74.53%
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct L023_ListNode {
    int val;
    struct L023_ListNode *next;
};

void L023_print_ListNode(struct L023_ListNode * h) {
    while (h != NULL) {
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\r\n");
}

int L023_cmp(struct L023_ListNode * l1, struct L023_ListNode * l2) {
    if (NULL == l1 && NULL == l2) return 0;
    if (l1 == NULL) return 1;
    if (l2 == NULL) return -1;
    if (l1->val < l2->val)
        return -1;
    if (l1->val > l2->val)
        return 1;
    return 0;
}

void L023_swap(struct L023_ListNode ** l1, struct L023_ListNode ** l2) {
    struct L023_ListNode * t = *l1;
    *l1 = *l2;
    *l2 = t;
}

void L023_swap_heap(struct L023_ListNode * heap, int i, int j) {
    struct L023_ListNode t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

struct L023_ListNode* L023_mergeKLists(struct L023_ListNode** lists, int listsSize) {
    struct L023_ListNode* head = (struct L023_ListNode *) malloc(sizeof(struct L023_ListNode));
    struct L023_ListNode* travel = head;
    struct L023_ListNode* temp = NULL;
    struct L023_ListNode* heap = (struct L023_ListNode *) malloc(sizeof(struct L023_ListNode) * listsSize);
    int i = 0, p = 0, c = 0, hi = 0;
    if (listsSize == 0) return NULL; 
    head->next = NULL;
    for (i = 0; i < listsSize; i ++) {
        if (*(lists+ i) != 0)        
        *(heap + (hi ++)) = *(*(lists + i)); 
    }
    //build heap
    for (i = (listsSize - 1) / 2; i > -1; i --) {
        //heap down
        p = i;
        c = 2 * p + 1;
        while (c < hi) {
            if (c + 1 < hi && L023_cmp(heap + c  + 1, heap + c) < 0) c ++;
            if (L023_cmp(heap + p, heap + c) > 0) {
                L023_swap_heap(heap, p, c);
            } else break;
            p = c;
            c = 2 * p + 1;
        }
    }
    while (heap != NULL) {
        temp = (struct L023_ListNode *) malloc(sizeof(struct L023_ListNode));
        temp->val = heap->val;
        temp->next = NULL;
        travel->next = temp;
        travel = temp;
        
        if (heap->next == NULL) {
            heap[0] = heap[hi - 1];
            hi --;
            if (hi == 0) break;
        } else {
            heap->val = heap->next->val;
            heap->next = heap->next->next;
        }
        
        //*heap = *(heap->next);
        //heap down
        p = 0;
        c = 2 * p + 1;
        while (c < hi) {
            if (c + 1 < hi && L023_cmp(heap + c  + 1, heap + c) < 0) c ++;
            if (L023_cmp(heap + p, heap + c) > 0) {
                L023_swap_heap(heap, p, c);
            } else break;
            p = c;
            c = 2 * p + 1;
        }
    }
    return head->next;
}

struct L023_ListNode * L023_convert_int_to_ListNode(int * arr, int n) {
    struct L023_ListNode * head = NULL;
    struct L023_ListNode * travel = NULL;
    struct L023_ListNode * temp = NULL;
    int i = 0;
    if (n == 0 || n < 0) return NULL;
    travel = (struct L023_ListNode *) malloc(sizeof(struct L023_ListNode));
    travel->val = *(arr + 0);
    travel->next = NULL;
    head = travel;
    for (i = 1; i < n; i ++) {
        temp = (struct L023_ListNode *) malloc(sizeof(struct L023_ListNode));
        temp->val = *(arr + i);
        temp->next = NULL;
        travel->next = temp;
        travel = travel->next;
    }
    return head;
}

void L023_free_ListNode(struct L023_ListNode * l) {
    struct L023_ListNode * temp = NULL;
    while (l != NULL) {
        temp = l->next;
        free(l);
        l = temp;
    }
}

int L023() {
    struct L023_ListNode** lists = NULL;
    int listsSize = 2;
    int i = 0;
    int len = 2;
    int a0[] = {1, 3};
    int *a1 = NULL;
    int **a;
    int count[] = {0, 2};
    struct L023_ListNode * answer = NULL;
    a = (int **) malloc(sizeof(int *) * len);
    *(a + 0) = a1;
    *(a + 1) = a0;
    lists = (struct L023_ListNode **) malloc(sizeof(struct L023_ListNode *) * listsSize);
    for (i = 0; i < listsSize; i ++) {
        *(lists + i) = L023_convert_int_to_ListNode(*(a + i), count[i]);
    }
    
    answer = L023_mergeKLists(lists, listsSize);

    L023_print_ListNode(answer);

    L023_free_ListNode(answer);

    free(a);
    for (i = 0; i < listsSize; i ++) {
        free(*(lists + i));
    }
    free(lists);
    
    printf("end\r\n");
    
    return 0;
}

