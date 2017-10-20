//
// Created by zxwtry on 17-10-20.
//

#include <stdio.h>
#include <string.h>

#define STRING "wtf"

void b01_p063() {
    char name[40];

    printf("input your name\n");
    scanf("%s", name);

    printf("strlen(name) is %d\n", strlen(name));
    printf("sizeof name is %d\n", sizeof name);

    printf("strlen(\"wtf\") is %d\n", strlen(STRING));
    printf("sizeof \"wtf\" is %d\n", sizeof STRING);

    /*
        strlen(name) is 4
        sizeof name is 40
        strlen("wtf") is 3
        sizeof "wtf" is 4
     */
    /*
     *  这里的sizeof 没有使用小括号
     *  sizeof(char)和sizeof(float)等必须使用小括号
     *  sizeof(name)和sizeof name是一样的
     */
}