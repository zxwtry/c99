//
// Created by zxwtry on 2018/5/31.
//


#include <stdlib.h>
#include <stdio.h>

void L022_add(char *** ans, int* size, int* cap, char * save, int saveLen) {
    char * add = (char *) malloc(sizeof(char) * (saveLen + 1));
    char ** tmp = NULL;
    int index = 0;
    add[saveLen] = '\0';
    for (index = 0; index < saveLen; ++index) {
        add[index] = save[index];
    }
    if (*size == *cap) {
        *cap = (*cap) * 2 + 1;
        tmp = (char **) malloc(sizeof(char *) * (*cap));
        for(index = 0; index < *size; index ++) {
            tmp[index] = (*ans)[index];
        }
        free(*ans);
        *ans = tmp;
    }
    (*ans)[(*size) ++] = add;
}


// AC 0ms 100.00 %
void L022_search(char * save, int lc, int rc, int saveLen, char *** ans, int * size, int * cap) {
    if (lc == rc && lc + rc == saveLen) {
        L022_add(ans, size, cap, save, saveLen);
        return;
    }
    if (lc + lc < saveLen) {
        save[lc + rc] = '(';
        L022_search(save, lc + 1, rc, saveLen, ans, size, cap);
    }
    if (lc > rc) {
        save[lc + rc] = ')';
        L022_search(save, lc, rc + 1, saveLen, ans, size, cap);
    }
}


char** L022_generateParenthesis(int n, int* returnSize) {
    int saveLen = 2 * n;
    char * save = (char *) malloc(sizeof(char) * saveLen);
    int cap = 100;
    char ** ans = (char **) malloc(sizeof(char *) * cap);
    * returnSize = 0;
    L022_search(save, 0, 0, saveLen, &ans, returnSize, &cap);
    return ans;
}

void L022() {
    int n = 3;
    int returnSize = 0;
    char ** ans = L022_generateParenthesis(n, &returnSize);
    for (int index = 0; index < returnSize; ++index) {
        printf("%d\t\t%s\n", index, ans[index]);
    }
}