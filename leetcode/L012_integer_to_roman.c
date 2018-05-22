//
// Created by zxwtry on 2018/5/22.
//


#include <malloc.h>
#include <stdio.h>

char L012_int_char(int num) {
    switch(num) {
        case 1:
            return 'I';
        case 5:
            return 'V';
        case 10:
            return 'X';
        case 50:
            return 'L';
        case 100:
            return 'C';
        case 500:
            return 'D';
        case 1000:
            return 'M';
    }
    return '\0';
}

// AC 68ms 45.79 %
char* L012_intToRoman(int num) {
    int base = 1;
    int numModTen = 0;
    char * ans = (char *) malloc(sizeof(char) * 100);
    int ansIndex = 0;
    int i = 0, j = 0;
    char c = 0;
    while (num != 0) {
        numModTen = num % 10;
        if (numModTen <= 3) {
            for (i = 0; i < numModTen; ++i) {
                ans[ansIndex ++] = L012_int_char(base);
            }
        } else if (numModTen == 4) {
            ans[ansIndex ++] = L012_int_char(base * 5);
            ans[ansIndex ++] = L012_int_char(base);
        } else if (numModTen < 9) {
            for (i = 5; i < numModTen; ++i) {
                ans[ansIndex ++] = L012_int_char(base);
            }
            ans[ansIndex ++] = L012_int_char(base * 5);
        } else {
            ans[ansIndex ++] = L012_int_char(base * 10);
            ans[ansIndex ++] = L012_int_char(base);
        }
        base = base * 10;
        num = num / 10;
    }
    i = 0;
    j = ansIndex - 1;
    while (i < j) {
        c = ans[i];
        ans[i] = ans[j];
        ans[j] = c;
        i ++;
        j --;
    }
    ans[ansIndex] = '\0';
    return ans;
}

void L012() {
    for (int val = 9; val < 68; ++val) {
        printf("val is %d\t\tans is %s\n", val, L012_intToRoman(val));
    }
}