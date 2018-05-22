//
// Created by zxwtry on 2018/5/22.
//


#include <stdio.h>

int L013_char_int(char num) {
    switch(num) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}

// AC 80ms 21.83 %
int L013_romanToInt(char* s) {
    int sIndex = 0;
    char c = 0;
    int valueNow = 0;
    int valueNxt = 0;
    int value = 0;
    while (1) {
        c = s[sIndex];
        if (c == '\0') {
            break;
        }
        valueNow = L013_char_int(s[sIndex]);
        valueNxt = L013_char_int(s[sIndex + 1]);
        if (valueNxt / valueNow == 5 || valueNxt / valueNow == 10) {
            value -= valueNow;
        } else {
            value += valueNow;
        }
        sIndex ++;
    }
    return value;
}

void L013() {
    int false = 0;
    for (int index = 1; index < 100; ++index) {
        char * s = L012_intToRoman(index);
        int newIndex = L013_romanToInt(s);
        printf("%d---%d\n", index, newIndex);
    }
}