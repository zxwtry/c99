//
// Created by zxwtry on 2018/5/17.
//

#include <stdbool.h>
#include <mem.h>
#include <malloc.h>
#include <stdio.h>


void L010_set(int* map, int row, int i, int j, int value) {
    //printf("set:%d\n", i * row + j);
    map[i * row + j] = value;
}

int L010_get(int* map, int row, int i, int j) {
    //printf("get:%d\n", row * i + j);
    return map[row * i + j];
}

void L010_print_matrix(int* map, int row, int col) {
    int ri = 0;
    int ci = 0;
    for (ri = 0; ri < col; ++ ri) {
        for (ci = 0; ci < row; ++ ci) {
            printf("%d ", L010_get(map, row, ri, ci));
        }
        printf("\n");
    }
}

// 动态规划
// . 可以替代任何字符
// * 让前面字符重复无数次（包括0次）
// map[i][j] 代表 i长度的s和j长度的p进行匹配
// 成功是1，不成功是0
// AC 20ms 51.21 %
bool L010_isMatch(char* s, char* p) {
    int sn = strlen(s);
    int pn = strlen(p);
    int size = 0;
    if (sn < pn) {
        size = (pn + 1) * (pn + 1);
    } else {
        size = (sn + 1) * (sn + 1);
    }
    int* map = (int *) malloc(sizeof(int) * size);
    int row = pn + 1;
    int si = 0;
    int pj = 0;
    int index = 0;
    bool ans = 0;
    memset(map, 0, sizeof(int) * size);
    for (index = (sn + 1) * (pn + 1) - 1;  index > -1 ; index --) {
        map[index] = 0;
    }
    L010_set(map, row, 0, 0, 1);
    // s的空字符和p的片段进行匹配
    for (pj = 1; pj < pn; pj ++) {
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
            // 2，p[pj] == s[si]，同时s[0, si-1]和p[0, pj-1]能够匹配
            if (L010_get(map, row, si - 1 + 1, pj - 1 + 1) == 1 && (s[si] == p[pj] || p[pj] == '.')) {
                L010_set(map, row, si + 1, pj + 1, 1);
            }
            // 3，p[pj-1, pj]能够匹配s[si]，同时s[0, si-1]和p[0, pj - 2]能够匹配
            if (pj > 1 && L010_get(map, row, si - 1 + 1, pj - 2 + 1) == 1 &&
                (p[pj] == '*' && (p[pj-1] == '.' || p[pj-1] == s[si]))) {
                L010_set(map, row, si + 1, pj + 1, 1);
            }
            // 4，匹配0次情况，同时s[0, si]和p[0, pj-2]能够匹配
            if (pj > 1 && L010_get(map, row, si + 1, pj - 2 + 1) == 1 &&
                    (p[pj] == '*')) {
                L010_set(map, row, si + 1, pj + 1, 1);
            }
        }
    }
    ans = L010_get(map, row, sn, pn) == 1;
    L010_print_matrix(map, row, sn + 1);
    free(map);
    return ans;
}

void L010_02_print(int* map, int size) {
    int index = 0;
    for (index = 0; index < size; ++index) {
        printf("%d ", map[index]);
    }
    printf("\n");
}
void L010_02_swap(int ** map, int size) {
    int * t = map[0];
    int index = 0;
    map[0] = map[1];
    map[1] = t;
    for (index = 0; index < size ; ++index) {
        map[1][index] = 0;
    }
}
// 可以对空间进行压缩
// 压缩到 2 * min(sn ,pn)
// 为了方便，这里只优化到 2 * pn
// AC 8ms 97.10 %
bool L010_02_isMatch(char* s, char* p) {
    int sn = strlen(s);
    int pn = strlen(p);
    int si = 0;
    int pi = 0;
    int * map[2];
    bool ans = 0;
    map[0] = (int *) malloc(sizeof(int) * (pn + 1));
    map[1] = (int *) malloc(sizeof(int) * (pn + 1));
    memset(map[0], 0, sizeof(int) * (pn + 1));
    memset(map[1], 0, sizeof(int) * (pn + 1));
    map[0][0] = 1;
    // 初始化 s空字符串 和 p的匹配
    // 需要 p[pi] == '*' 同时 s空 和 p[0, pi - 2]
    for (pi = 1; pi < pn; ++ pi) {
        if (p[pi] == '*' && map[0][pi - 2 + 1] == 1) {
            map[0][pi + 1] = 1;
        }
    }

    //L010_02_print(map[0], pn + 1);
    for (si = 0; si < sn; ++si) {
        for (pi = 0; pi < pn; ++pi) {
            map[si+1-si][pi+1] = 0;
            // s[si] == p[pi] 同时 s[0, si-1] 和 p[0, pi-1] 匹配
            if ((s[si] == p[pi] || p[pi] == '.') && map[si-1+1-si][pi-1+1] == 1) {
                map[si+1-si][pi+1] = 1;
            }
            // s[si] 和 p[pi-1, pi]匹配，同时s[0, si-1]和p[0, pi-2]匹配（用一次）
            if (pi > 0 && map[si-1+1-si][pi-2+1] == 1 && (
                    p[pi] == '*' && (p[pi-1] == '.' || p[pi-1] == s[si]))) {
                map[si+1-si][pi+1] = 1;
            }
            // s[si] 和 p[pi-1, pi]匹配，同时s[0, si-1]和p[0, pi]匹配（用多次）
            if (pi > 0 && map[si-1+1-si][pi+1] == 1 &&(
                    p[pi] == '*' && ((p[pi-1] == '.' || p[pi-1] == s[si])))) {
                map[si+1-si][pi+1] = 1;
            }
            // p[pi] == '*' 同时 s[0, si]和p[0, pi-2]匹配（用零次）
            if (pi > 0 && map[si+1-si][pi-2+1] == 1 && p[pi] == '*') {
                map[si+1-si][pi+1] = 1;
            }
        }
        L010_02_swap(map, pn + 1);
        map[0][0] = 0;
        //L010_02_print(map[0], pn + 1);
    }
    ans = map[0][pn] == 1;
    free(map[0]);
    free(map[1]);
    return ans;
}

void L010() {
    // "aaa"
    //"ab*ac*a"
    char* s = "bb";
    char* p = "c*";
    printf("ans is %d", L010_02_isMatch(s, p));
//    int size = 0;
//    scanf("%d", &size);
//    int* map = (int *) malloc(sizeof(int) * size);
//    memset(map, 0, sizeof(int) * size);
//    map[101] = 100;
//    free(map);
}