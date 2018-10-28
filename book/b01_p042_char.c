//
// Created by zxwtry on 2017/10/17.
//

#include <stdio.h>

/*
 *  ASCII: 0-127
 *  \0oo 和 \xhh是ASCII码的专用表示方法
 *  \0八进制
 *  \x十六进制
 *
 */

void b01_p042() {
    char a = 97;
    printf("%c\n", a);      //输出a

    int b = '\032';
    printf("%d\n", b);      //输出26

    int c = '\x32';         //输出50
    printf("%d\n", c);

}