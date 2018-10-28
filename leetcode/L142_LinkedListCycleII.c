/*
    url: /leetcode.com/problems/linked-list-cycle-ii
    AC 6ms 28.24%
*/

#include <stdio.h>
#include <stdlib.h>

struct L142_ListNode {
    int val;
    struct L142_ListNode *next;
};

struct L142_ListNode * L142_detectCycle(struct L142_ListNode *head) {
    struct L142_ListNode * fast = head;
    struct L142_ListNode * slow = head;
    while (1) {
        if (fast == 0 || slow == 0) return NULL;
        if (fast->next == 0) return 0;
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    }
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}