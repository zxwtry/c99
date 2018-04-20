//
// Created by zxwtry on 2017/11/3.
//

/*
    sizeof运算符和size_t类型

 */

#include <stdio.h>

/*
    sizeof 返回 size_t类型的值
    size_t是一个无符号整数类型
    typedef unsigned int size_t
 */

void b01_p095_sizeof() {
    int n = 0;
    size_t int_size;
    int_size = sizeof(int);
    printf("int_size is %d\n", int_size);
    /*
        int_size is 4
     */
}


/*
    负整数除法
    正负号：负负得正
 */
void b01_p097_negative_division() {
    printf("11 / 5 is %d\n", 11 / 5);
    printf("(-11) / 5 is %d\n", (-11) / 5);
    printf("11 / (-5) is %d\n", 11 / (-5));
    printf("(-11) / (-5) is %d\n", (-11) / (-5));
    /*
        11 / 5 is 2
        (-11) / 5 is -2
        11 / (-5) is -2
        (-11) / (-5) is 2
     */

    printf("10 / 4 is %d\n", 10 / 4);
    printf("(-10) / 4 is %d\n", (-10) / 4);
    printf("10 / (-4) is %d\n", 10 / (-4));
    printf("(-10) / (-4) is %d\n", (-10) / (-4));

    /*
        10 / 4 is 2
        (-10) / 4 is -2
        10 / (-4) is -2
        (-10) / (-4) is 2
     */
}


/*
    负整数取余
    正负号：依第一个数的正负号
 */
void b01_p097_negative_mod() {
    printf("11 %% 5 is %d\n", 11 % 5);
    printf("(-11) %% 5 is %d\n", (-11) % 5);
    printf("11 %% (-5) is %d\n", 11 % (-5));
    printf("(-11) %% (-5) is %d\n", (-11) % (-5));
    /*
        11 % 5 is 1
        (-11) % 5 is -1
        11 % (-5) is 1
        (-11) % (-5) is -1
     */

    printf("10 %% 4 is %d\n", 10 % 4);
    printf("(-10) %% 4 is %d\n", (-10) % 4);
    printf("10 %% (-4) is %d\n", 10 % (-4));
    printf("(-10) %% (-4) is %d\n", (-10) % (-4));

    /*
        10 % 4 is 2
        (-10) % 4 is -2
        10 % (-4) is 2
        (-10) % (-4) is -2
     */
}

void b01_p095() {
    b01_p097_negative_mod();
}


