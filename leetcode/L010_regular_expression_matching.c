//
// Created by zxwtry on 2018/5/17.
//

#include <stdbool.h>
#include <mem.h>
#include <malloc.h>


void L010_set(int* map, int row, int i, int j, int value) {
    map[i * row + j] = value;
}

int L010_get(int* map, int row, int i, int j) {
    return map[row * i + j];
}

// 动态规划
// . 可以替代任何字符
// * 让前面字符重复无数次（包括0次）
// map[i][j] 代表 i长度的s和j长度的p进行匹配
// 成功是1，不成功是0
//
bool isMatch(char* s, char* p) {
    int sn = strlen(s);
    int pn = strlen(p);
    int* map = (int *) malloc(sizeof(int) * (sn + 1) * (pn + 1));
    int row = sn + 1;
    int si = 0;
    int pj = 0;
    memset(map, 0, sizeof(int) * (sn + 1) * (pn + 1));
    L010_set(map, row, 0, 0, 1);
    // s的空字符和p的片段进行匹配
    for (pj = 1; pj < sn; pj += 2) {
        if (L010_get(map, row, 0, pj - 2 + 1) == 1 && p[pj] == '*') {
            L010_set(map, row, 0, pj + 1, 1);
        }
    }
    for (si = 0; si < sn; ++ si) {
        for (pj = 0; pj < pn; ++ pj) {
            // s[0, si]和p[0,pj]是否匹配，看这么几种情况
            // 1，p[pj-1, pj]能够匹配s[si]，同时s[0, si-1]和p[0, pj]能够匹配
            if (L010_get(map, row, si - 1 + 1, pj + 1) == 1 && (
                    (pj > 0) && (p[pj] == '*' && (p[pj-1] == '.' || p[pj-1] == s[si]))
                    )) {
                L010_set(map, row, si + 1, pj + 1, 1);
            }
            // 2，p[pj] === s[si]，同时s[0, si-1]和p[0, pj-1]能够匹配
            if (L010_get(map, row, si - 1 + 1, pj - 1 + 1) == 1 && s[si] == p[pj]) {
                L010_set(map, row, si + 1, pj + 1, 1);
            }
        }
    }
}


void L010() {

}