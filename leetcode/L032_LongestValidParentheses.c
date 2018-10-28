/*
    url: leetcode.com/problems/longest-valid-parentheses/
    9ms 21.28%
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//vc do not need below, leetcode need
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

struct L032_stk {
    int val;
    struct L032_stk * pre;
    struct L032_stk * nxt;
};

struct L032_stk * stk_push(struct L032_stk * top, int val) {
    struct L032_stk * t = (struct L032_stk *) malloc(sizeof(struct L032_stk));
    t->val = val;
    t->pre = top;
    t->nxt = NULL;
    if (top != NULL) top->nxt = t;
    return t;
};

struct L032_stk * L032_stk_pop(struct L032_stk * top) {
    struct L032_stk * t = top == NULL ? NULL : top->pre;
    if (top == NULL) return NULL;
    if (t != NULL) t->nxt = NULL;
    free(top);
    return t;
};

void L032_stk_free(struct L032_stk * top) {
    struct L032_stk * t = NULL;
    while (top != NULL) {
        t = top->pre;
        free(top);
        top = t;
    }
}

int L032_longestValidParentheses(char* s) {
    int lft = 0, rgt = 0, cnt = 0, ans = 0, i = 0, len = 0;
    struct L032_stk * top = NULL;
    char * m = NULL;
    len = s == NULL ? 0 : strlen(s);
    for (lft = 0, rgt = 0, i = 0; i < len; i ++) {
        if (* (s + i) == '(') lft ++;
        else rgt ++;
    }
    if (lft == 0 || rgt == 0) return 0;
    m = (char *) malloc(sizeof(char) * len);
    memset(m, '\0', len);
    for (i = 0; i < len; i ++) {
        if (*(s + i) == '(') {
            top = stk_push(top, i);
        } else if (top != NULL) {
            *(m + i) = 1;
            *(m + top->val) = 1;
            top = L032_stk_pop(top);
        }
    }
    for (i = 0; i < len; i ++) {
        cnt = *(m + i) == 1 ? cnt+1 : 0;
        ans = max(ans, cnt);
    }
    free(m);
    L032_stk_free(top);
    return ans;
}

int L032() {
    char * s = "(())";
    printf("answer is %d\r\n", L032_longestValidParentheses(s));
    return 0;
}