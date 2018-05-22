//
// Created by zxwtry on 2018/5/22.
//

#include <mem.h>
#include <malloc.h>
#include <stdio.h>

// AC 4ms 99.70 %
char* L014_longestCommonPrefix(char** strs, int strsSize) {
    int minLen = 1 << 30;
    int tmp = 0;
    int strsIndex = 0;
    int index = 0;
    char * ans = NULL;
    char c = 0;
    int b = 0;
    for (strsIndex = 0; strsIndex < strsSize; ++strsIndex) {
        tmp = strlen(strs[strsIndex]);
        minLen = minLen < tmp ? minLen : tmp;
    }
    if (minLen == 0 || minLen == 1 << 30) return "";
    minLen ++;
    ans = (char *) malloc(sizeof(char) * minLen);
    for (index = 0; index < minLen; ++index) {
        c = strs[0][index];
        for (strsIndex = 1; strsIndex < strsSize; ++strsIndex) {
            if (c != strs[strsIndex][index]) {
                b = 1;
            }
        }
        if (b) {
            break;
        } else {
            ans[index] = c;
        }
    }
    ans[index] = '\0';
    return ans;
}

void L014() {
    int strsSize = 3;
    char ** strs = (char **) malloc(sizeof(char *) * strsSize);
    // Input: ["flower","flow","flight"]
    strs[0] = "flower";
    strs[1] = "flow";
    strs[2] = "flight";
    printf("ans is %s\n", L014_longestCommonPrefix(strs, strsSize));
}