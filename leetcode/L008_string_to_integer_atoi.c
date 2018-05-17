//
// Created by zxwtry on 2018/5/17.
//



#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <limits.h>

// AC 16ms 77.44 %
int L008_myAtoi(char* str) {
    int startIndex = 0;
    int isPositive = 1;
    int value = 0;
    int strLen = strlen(str);
    char c = 0;
    int add = 0;
    int positiveLimit1 = INT_MAX / 10;
    int positiveLimit2 = INT_MAX % 10;
    int negativeLimit1 = INT_MIN / 10;
    int negativeLimit2 = INT_MIN % 10;

    while (startIndex < strLen) {
        if (str[startIndex] == ' ') {
            startIndex ++;
        } else {
            break;
        }
    }
    if (startIndex < strLen && str[startIndex] == '+') {
        startIndex ++;
    } else if (startIndex < strLen &&  str[startIndex] == '-') {
        isPositive = 0;
        startIndex ++;
    }

    while (startIndex < strLen) {
        c = str[startIndex];
        if (c >= '0' && c <= '9') {
            if (isPositive) {
                add = c - '0';
                if (value > positiveLimit1 || (value == positiveLimit1 && add > positiveLimit2)) {
                    return INT_MAX;
                } else {
                    value = value * 10 + add;
                }
            } else {
                add = -c + '0';
                if (value < negativeLimit1 || (value == negativeLimit1 && add < negativeLimit2)) {
                    return INT_MIN;
                } else {
                    value = value * 10 + add;
                }
            }
        } else {
            break;
        }
        startIndex ++;
    }
    return value;
}

void L008() {
    char t [][40] = {
            "+123",
            "-123",
            "++123",
            "--123",
            "   -42",
            "4193 with words",
            "words and 987",
            "-91283472332"
    };
    for (int i = 0; i < 8; ++i) {
        printf("index:%d\t\tvalue:%s\t\tatoi:%d\t\tmy:%d\n", i , t[i], atoi(t[i]),L008_myAtoi(t[i]));
        //printf("index:%d\t\tvalue:%s\tv:%d\n", i , t[i], atoi(t[i]));
    }
}
