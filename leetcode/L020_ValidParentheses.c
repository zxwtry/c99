/*
    url: leetcode.com/problems/valid-parentheses/
    3ms 23.11%
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int

struct L020_stack {
    char c;
    struct L020_stack * next;
    struct L020_stack * last;
};

struct L020_stack * L020_push_stack(char c, struct L020_stack * stk) {
    struct L020_stack * temp = (struct L020_stack *) malloc(sizeof(struct L020_stack));
    temp->next = NULL;
    temp->last = NULL;
    temp->c = c;
    if (stk != NULL)
        stk->next = temp;
    temp->last = stk;
    return temp;
};

struct L020_stack * L020_pop_stack(struct L020_stack * stk) {
    struct L020_stack * last = NULL;
    if (stk == NULL) return stk;
    last = stk->last;
    free(stk->next);
    return last;
};

bool L020_isValid(char* s) {
    int i = 0, r = strlen(s);
    char c = '\0', t = '\0';
    struct L020_stack * head = NULL;
    for (i = 0; i < r; i ++) {
        c = *(s + i);
        if (c == '(') {
            head = L020_push_stack(')', head);
        } else if (c == '{') {
            head = L020_push_stack('}', head);
        } else if (c == '[') {
            head = L020_push_stack(']', head);
        } else if (head == NULL) {
            return 0;
        } else {
            t = head->c;
            head = head->last;
            if (t != c) {
                return 0;
            }
        }
    }
    //ans
    i = head == NULL;
    //free
    while (head != NULL) {
        head = L020_pop_stack(head);
    }
    return i;
}

int L020() {
    char *s = ")";
    printf("answer is %d\r\n", L020_isValid(s));
}