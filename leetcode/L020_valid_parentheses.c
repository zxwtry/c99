//
// Created by zxwtry on 2018/5/30.
//

#include <stdbool.h>
#include <mem.h>
#include <malloc.h>
#include <stdio.h>

// AC 0ms 100.00 %
bool L020_isValid(char* s) {
    int n = strlen(s);
    char * stk = (char *) malloc(sizeof(char) * n);
    int stk_index = 0;
    int index = 0;
    char c;
    for (index = 0; index < n; ++index) {
        c = s[index];
        switch(c) {
            case '(':
                stk[stk_index ++] = ')';
                break;
            case '[':
                stk[stk_index ++] = ']';
                break;
            case '{':
                stk[stk_index ++] = '}';
                break;
            default:
                if (stk_index != 0 && stk[stk_index - 1] == c) {
                    stk_index --;
                } else {
                    return 0;
                }
                break;
        }
    }
    return stk_index == 0;
}

void L020() {
    char * s = "(){([])}";
    printf("ans is %d\n", L020_isValid(s));
}