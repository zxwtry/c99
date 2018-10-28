/*
    url: leetcode.com/problems/linked-list-cycle
    AC 6ms 19.26%
*/

struct L141_ListNode {
    int val;
    struct L141_ListNode *next;
};

typedef int bool;

bool L141_hasCycle(struct L141_ListNode *head) {
    struct L141_ListNode * fast = head;
    struct L141_ListNode * slow = head;
    while (1) {
        if (fast == 0 || slow == 0) return 0;
        if (fast->next == 0) return 0;
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return 1;
    }
    return 0;
}

