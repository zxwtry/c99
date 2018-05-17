//
// Created by zxwtry on 2018/5/16.
//


#include <mem.h>
#include <malloc.h>
#include <stdio.h>

void L006_addToCharArray(char* s, int sn, int si, char* target, int* index) {
    if (si < sn) {
        target[*index] = s[si];
        *index = *index + 1;
    }
}


// AC 20ms 76.26 %
char* L006_convert(char* s, int numRows) {
    if (numRows <= 1) {
        return s;
    }
    int sn = strlen(s);
    int circle = 2 * numRows - 2;
    int numCols = sn % circle == 0 ? sn / circle : sn / circle + 1;
    int colIndex = 0;
    int rowIndex = 0;
    char * ans = (char *) malloc(sizeof(char) * (sn + 1));
    int ansIndex = 0;
    // 处理第一行
    for (colIndex = 0; colIndex < numCols; colIndex ++) {
        L006_addToCharArray(s, sn, colIndex * circle, ans, &ansIndex);
    }
    // 处理中间行
    for (rowIndex = 1;  rowIndex < numRows - 1; rowIndex ++) {
        // 有两个
        for (colIndex = 0; colIndex < numCols; ++colIndex) {
            L006_addToCharArray(s, sn, colIndex * circle + rowIndex, ans, &ansIndex);
            L006_addToCharArray(s, sn, colIndex * circle + circle - rowIndex, ans, &ansIndex);
        }
    }
    // 处理最后一行
    for (colIndex = 0; colIndex < numCols; ++ colIndex) {
        L006_addToCharArray(s, sn, colIndex * circle + numRows - 1, ans, &ansIndex);
    }
    ans[sn] = '\0';
    return ans;
}

void L006() {
    char * s = "PAYPALISHIRING";
    int numRows = 4;
    char * ans = L006_convert(s, numRows);
    printf("ans is %s\n", ans);
}

