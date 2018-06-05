//
// Created by zxwtry on 2018/6/4.
//


#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <mem.h>

void L030_getNext(char * p, int pn, int * next) {
    int bi = 0, fi = 2;
    if (pn < 2) {
        // 外部保证next的长度至少为1
        next[0] = -1;
        return;
    }
    next[0] = -1;
    next[1] = 0;
    while (fi < pn) {
        if (p[bi] == p[fi - 1]) {
            next[fi ++] = ++ bi;
        } else if (bi <= 0) {
            next[fi ++] = 0;
        } else {
            bi = next[bi];
        }
    }
}


void L030_print_array(int * array, int size) {
    int index = 0;
    for (index = 0; index < size; ++index) {
        printf("%d\t\t%d\n", index, array[index]);
    }
}


void L030_findIndex(char * s, int sn, char * p, int pn, int * next, int * ans, int ansValue) {
    int si = 0;
    int pi = 0;
    L030_getNext(p, pn, next);
    while (si < sn) {
        if (s[si] == p[pi]) {
            si ++;
            pi ++;
            if (pi == pn) {
                ans[si - pn] = ansValue;
                si -= pn - 1;
                pi = 0;
            }
        } else if (next[pi] == -1) {
            si ++;
        } else {
            pi = next[pi];
        }
    }
}


void L030_02_findIndex(char * s, int sn, char * p, int pn, int * next, int * ans, int ansValue) {
    int si = 0, pi = 0;
    int all = 1;
    for (si = 0; si <= sn - pn; ++si) {
        all = 1;
        for (pi = 0; all & pi < pn; ++pi) {
            if (s[si + pi] != p[pi]) {
                all = 0;
            }
        }
        if (all) {
            ans[si] = ansValue;
        }
    }
}


int L030_string_equals(char * a, char * b) {
    int i = 0;
    if (a == b) return 1;
    if (a == NULL || b == NULL) return 0;
    while (a[i] == b[i]) {
        if (a[i] == '\0') {
            return 1;
        }
        i ++;
    }
    return 0;
}


// 这个，调试没有问题，提交会runtime error
int* L030_findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int * match = NULL;
    int index;
    int * next = NULL;
    int pn;
    int sn = strlen(s);
    int endIndex = 0;
    int allMatch;
    int wordIndex = 0;
    int * ans = NULL;
    int * cnt = (int *) malloc(sizeof(int) * wordsSize);
    int * cut = (int *) malloc(sizeof(int) * wordsSize);
    int wordsLen = 0;
    int cutIndex = 0;
    *returnSize = 0;
    if (wordsSize == 0) {
        return NULL;
    }
    memset(cnt, 0, sizeof(int) * wordsSize);
    for (wordIndex = 0; wordIndex < wordsSize; ++wordIndex) {
        allMatch = 1;
        for (index = 0; allMatch == 1 && index < wordsLen; ++index) {
            if (L030_string_equals(words[index], words[wordIndex])) {
                allMatch = 0;
                cnt[index] ++;
            }
        }
        if (allMatch) {
            cnt[wordsLen] = 1;
            words[wordsLen ++] = words[wordIndex];
        }
    }
    ans = (int *) malloc(sizeof(int) * sn);
    pn = strlen(words[0]);
    next = (int *) malloc(sizeof(int) * (pn + 2));
    match = (int *) malloc(sizeof(int) * sn);
    memset(match, 0, sizeof(int) * sn);
    //L030_print_array(cnt, wordsLen);
    for (index = 0; index < wordsLen; ++index) {
        L030_02_findIndex(s, sn, words[index], pn, next, match, index + 1);
    }
    for (index = 0; index < wordsLen; ++index) {
        cut[index] = cnt[index];
    }
    //L030_print_array(match, sn);
    endIndex = sn - wordsSize * pn;
    if (endIndex < 0) {
        return NULL;
    }
    for (index = 0; index <= endIndex; ++index) {
        allMatch = 1;
        for (wordIndex = 0; wordIndex < wordsLen; ++wordIndex) {
            cut[wordIndex] = cnt[wordIndex];
        }
        for (wordIndex = 0; allMatch && wordIndex < wordsLen; ++wordIndex) {
            cutIndex = match[index + pn * wordIndex];
            if (cutIndex > 0) {
                cut[cutIndex - 1] --;
                if (cut[cutIndex - 1] < 0) {
                    allMatch = 0;
                }
            } else {
                allMatch = 0;
            }
        }
        if (allMatch) {
            ans[(*returnSize) ++] = index;
        }
    }
    free(cut);
    free(cnt);
    free(match);
    return ans;
}


// 采用Solution中的方法
void L030_02_getWordsIndex(char* s, char** words, int wordsSize, int *wordsind) {
    memset(wordsind, 0xff, sizeof(int) * strlen(s));
    for (int n = 0; n < wordsSize; n++) {
        char *substr = s;
        while (substr = strstr(substr, words[n])) {
            if (wordsind[substr - s] == -1)wordsind[substr - s] = n;
            substr++;
        }
    }
}


int L030_02_getMapWords(char** words, int wordsSize, int *wordsCount) {
    for (int i = 0; i < wordsSize; i++) {
        wordsCount[i] = 1;
    }
    for (int i = 0; i < wordsSize; i++) {
        if (!words[i]) continue;
        for (int j = i + 1; j < wordsSize; j++) {
            if (!words[j])continue;
            if (!strcmp(words[i], words[j])) {
                wordsCount[i] ++;
                words[j] = NULL;
            }
        }
    }
    int c = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (words[i])words[c++] = words[i];
    }
    return c;
}


int* L030_02_findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    char **words_new = (char **)malloc(sizeof(char*) * wordsSize);
    memcpy(words_new, words, sizeof(char*) *wordsSize);
    int nLen = strlen(s);
    int *wordsCount = (int*)malloc(sizeof(int) * wordsSize);
    int uniqueWordsSize = L030_02_getMapWords(words_new, wordsSize, wordsCount);
    int nWordLen = strlen(words_new[0]);
    int *wordsind = (int*)malloc(sizeof(int) * nLen);
    L030_02_getWordsIndex(s, words_new, uniqueWordsSize, wordsind);
    int *fullflag = (int*)malloc(uniqueWordsSize * sizeof(int));
    int *result = (int*)malloc(sizeof(int) * nLen);
    int n, i, j;
    int c = 0;
    for (n = 0; n < nWordLen; n++) {
        for (i = n; i < nLen; i += nWordLen) {
            memset(fullflag, 0, uniqueWordsSize * sizeof(int));
            for (j = 0; j < wordsSize; j++) {
                if (i + j * nWordLen >= nLen)break;
                int nWord = wordsind[i + j * nWordLen];
                if (nWord == -1)break;//there is no word
                if (fullflag[nWord] >= wordsCount[nWord])break;//beyond the max count
                fullflag[nWord]++;//count it
            }
            if (j == wordsSize) {
                result[c++] = i;
            }
        }
    }
    free(wordsind);
    free(fullflag);
    free(wordsCount);
    free(words_new);
    *returnSize = c;
    if (c == 0)return NULL;
    else return result;
}


void L030() {
    /*
    "abaababbaba"
["ab","ba","ab","ba"]
     */

    // int* L030_findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    char * s = "aaabbbc";
    int wordsSize = 4;
    char * words[5];
    int returnSize = 0;
    int *ans = NULL;
    words[0] = "a";
    words[1] = "b";
    words[2] = "c";
    words[3] = "b";
    words[4] = "c";
    ans = L030_findSubstring(s, words, wordsSize, &returnSize);
    printf("ans size: %d\n", returnSize);
    L030_print_array(ans, returnSize);
}
