//
// Created by zxwtry on 2018/5/15.
//

#include <stdio.h>

int L003_getLengthOfCharArray(char * s) {
    int len = 0;
    while (*(s + len) != '\0') {
        len ++;
    }
    return len;
}

int L003_min(int a, int b) {
    return a < b ? a : b;
}

int L003_max(int a, int b) {
    return a < b ? b : a;
}

// AC 16ms 87.82%
int L003_lengthOfLongestSubstring(char* s) {
    int LEN = 256;
    int map[256];
    for (int i = 0; i < LEN; ++i) {
        map[i] = -1;
    }
    int index = 0;
    int current = 0;
    int answer = 0;
    while (1) {
        int c = s[index];
        if (c == 0) {
            break;
        }
        current ++;
        current = L003_min(current, index - map[c]);
        answer  = L003_max(current, answer);
        map[c] = index;
        index ++;
    }
    return answer;
}

void L003() {
    char * s = "pwwkew";
    printf("len is %d\n", L003_lengthOfLongestSubstring(s));
}