//
// Created by zxwtry on 2018/5/28.
//

#include <malloc.h>
#include <stdlib.h>
#include <mem.h>
#include <stdio.h>


void L017_add(char *** ans, int* cap, int* size, char * one, int one_size) {
    char * add = (char*) malloc(sizeof(char) * (one_size + 1));
    char ** tmp = NULL;
    int i = 0;
    add[one_size] = '\0';
    for (i = 0; i < one_size ; ++i) {
        add[i] = one[i];
    }
    if (*size == *cap) {
        *cap = 2 * (*cap) + 1;
        tmp = (char **) malloc(sizeof(char *) * (*cap));
        for (i = 0; i < *size; ++i) {
            tmp[i] = (*ans)[i];
        }
        free(*ans);
        *ans = tmp;
    }
    (*ans)[(*size) ++] = add;
}


char * L017_getChar(char num) {
    switch(num) {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
    }
    return "";
}


void L017_search(char *** ans, int * cap, int * size, char * one, int one_index, int one_size, char * digits, int digits_index) {
    char * cs = NULL;
    int csIndex = 0;
    char c;
    if (digits[digits_index] == '\0') {
        L017_add(ans, cap, size, one, one_size);
        return;
    }
    cs = L017_getChar(digits[digits_index]);
    while (1) {
        c = cs[csIndex ++];
        if (c == '\0') {
            break;
        }
        one[one_index] = c;
        L017_search(ans, cap, size, one, one_index + 1, one_size, digits, digits_index + 1);
    }
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// AC 0ms 100.00 %
char** L017_letterCombinations(char* digits, int* returnSize) {
    int cap = 1000, one_size = strlen(digits);
    char ** ans = (char **) malloc(sizeof(char*) * cap);
    char * one = (char *) malloc(sizeof(char)  * (one_size + 1));
    if (one_size == 0) {
        return ans;
    }
    one[one_size] = '\0';
    *returnSize = 0;
    L017_search(&ans, &cap, returnSize, one, 0, one_size, digits, 0);
    return ans;
}


void L017() {
    char * digits = "23";
    int returnSize = 0;
    char ** ans = L017_letterCombinations(digits, &returnSize);
    printf("size is %d", returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d\t\t%s\n", i, ans[i]);
    }
}