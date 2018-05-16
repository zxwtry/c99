//
// Created by zxwtry on 2018/5/16.
//

#include <stdio.h>
#include <mem.h>
#include <malloc.h>

// 理解错了，这个写成了，最长无重复子串
char* L005_01_longestPalindrome(char* s) {
    int ansIndex = 0;     // 回文串的开始位置
    int ansLength = 0;         // 回文串的长度
    char* ans = NULL;       // 返回指针
    int index = 0;          // s的index
    int length = 0;         // 遍历过程中记录的长度
    int c = 0;              // s的每一个字符
    int map[256];           // 标记c每一次出现的位置
    memset(map, -1, 256 * sizeof(int));   // 标记c上一次出现的位置，初始为-1
    while (1) {
        c = s[index];
        if (c == 0) {
            break;          // 字符串遍历完成
        }

        length ++;
        if (length > index - map[c]) {
            length = index - map[c];
        }

        if (length > ansLength) {
            // 记录最长
            ansLength = length;
            ansIndex = index + 1 - ansLength;
        }

        map[c] = index;     // 更新c的上一次出现位置为index
        index ++;
    }
    ans = (char*) malloc(sizeof(char) * (ansLength + 1));
    // strcpy(ans, s + ansIndex);
    // 重新使用index
    for (index = 0; index < ansLength; ++ index) {
        ans[index] = s[ansIndex + index];
    }
    ans[ansLength] = '\0';
    return ans;
}


int getCharIndex(char * s , int index) {
    if (index % 2 == 0) {
        return -1;
    } else {
        return s[index / 2];
    }
}

int L005_min(int a, int b) {
    return a < b ? a : b;
}

int L005_max(int a, int b) {
    return a < b ? b : a;
}

void L005_print(int * arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("index:%d\t\tvalue:%d\n", i, arr[i]);
    }
}


// 采用manacher
// AC 44ms 53.98 %
char* L005_02_longestPalindrome(char* s) {
    int nn = 2 * strlen(s) + 1;
    int li = 0;             // 上一个中心位置
    int ti = 0;             // 最远到达的位置
    int mi = 0;             // mirror indexk
    int maxIndex = 0;       // 最长的index，保存
    int i = 0;
    int left = 0;
    int right = 0;
    int * rs = (int *) malloc(nn * sizeof(int));
    char * ans = NULL;
    memset(rs, 0, nn * sizeof(int));
    while (ti <= nn - 1) {
        mi = 2 * li - i;
        if (rs[mi] + i >= ti) {
            left = i;
            right = i;
            while (left - 1 >= 0 && right + 1 < nn && getCharIndex(s, left - 1) == getCharIndex(s, right + 1)) {
                left --;
                right ++;
            }
            ti = L005_max(ti, right);
            li = i;
            rs[i] = (right - left) / 2;
        } else {
            rs[i] = L005_min(ti - i, rs[mi]);
        }
        if (rs[maxIndex] < rs[i]) {
            maxIndex = i;
        }
        i ++;
    }
    // 重用li，这里代表需要截取的字符串的开始下标
    li = (maxIndex - rs[maxIndex]) / 2;
    ans = (char *) malloc(sizeof(char) * (rs[maxIndex] + 1));
    for (i = 0; i < rs[maxIndex]; ++ i) {
        ans[i] = s[li + i];
    }
    ans[rs[maxIndex]] = '\0';
    return ans;
}

void L005() {
    char* s = "abad";
    printf("ans is %s\n", L005_02_longestPalindrome(s));
}