/*
    url: leetcode.com/problems/sudoku-solver/
    19ms 11.43%
*/

#include <stdio.h>
#include <stdlib.h>

#define bool int

int L037_isValid(char** b, int x, int y) {
	int i = 0, j = 0, k = 0;
    for (k = 0; k < 9; k ++) {
        if (k != x && b[k][y] == b[x][y])
			return 0;
        if (k != y && b[x][k] == b[x][y])
			return 0;
        i = (x / 3) * 3 + k / 3;
        j = (y / 3) * 3 + k % 3;
        if ((i != x || j != y) && b[i][j] == b[x][y])
            return 0;
    }
	return 1;
}

bool L037_solveSudoku2(char** b) {
    int i = 0, j = 0, k = 0;
	for (i = 0; i < 9; ++i)
		for (j = 0; j < 9; ++j) {
			if (b[i][j] != '.') continue;
			for (k = 0; k < 9; ++k) {
				b[i][j] = (char) ('1' + k);
				if (L037_isValid(b, i, j) && L037_solveSudoku2(b))
					return 1;
				b[i][j] = '.';
			}
			return 0;
		}
	return 1;
}

void L037_solveSudoku(char** b, int rs, int cs) {
    int val = L037_solveSudoku2(b);
    printf("answer is %d\r\n", val);
}

char* L037_setChar(char* src, int n) {
    int i = 0;
    char* dst = (char*)malloc(sizeof(char) * (n + 1));
    for (i = 0; i <= n; i ++)
        *(dst + i) = *(src + i);
    return dst;
}

int L037() {
    char** b = (char **) malloc(sizeof(char *) * 9);
    char* t = NULL, * tt = NULL;
    int rs = 9, cs = 9, i = 0, j = 0;
    b[0] = L037_setChar("..9748...", 9);
    b[1] = L037_setChar("7........", 9);
    b[2] = L037_setChar(".2.1.9...", 9);
    b[3] = L037_setChar("..7...24.", 9);
    b[4] = L037_setChar(".64.1.59.", 9);
    b[5] = L037_setChar(".98...3..", 9);
    b[6] = L037_setChar("...8.3.2.", 9);
    b[7] = L037_setChar("........6", 9);
    b[8] = L037_setChar("...2759..", 9);
    L037_solveSudoku(b, rs, cs);
    for (i = 0; i < 9; i ++) {
        for (j = 0; j < 9; j ++) {
            printf("%c ", b[i][j]);
        }
        printf("\r\n");
    }
    for (i = 0; i < 9; i ++)
        free(*(b + i));
    free(b);
    return 0;
}
