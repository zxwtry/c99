//
// Created by zxwtry on 17-10-21.
//


/*
    scanf   基本变量类型      &变量名
    scanf   字符数组         变量名
 */

/*
    scanf   基本和   printf   相同
    区别一：
        printf 把%f %e %E %g %G同时用于float类型和double类型
        scanf  把%f %e %E %g %G只能用于float类型

 */

/*
    float  范围：  -2^128   ~~~  2^128
                  3.40E38
    double 范围：  -2^1024  ~~~  2^1024
                  1.79E308
 */

/*
    输入float   -->  %f
    输入double  -->  %lf
 */

/*
    scanf转换说明：

    %c              --> 一个字符
    %d              --> 有符号的十进制数
    %e,%f,%g,%a     --> 浮点数  (%a是C99标准)
    %E,%F,%G,%A     --> 浮点数  (%A是C99标准)
    %i              --> 有符号十进制整数
    %o              --> 有符号八进制整数
    %p              --> 指针(一个地址)
    %s              --> 字符串，空白字符分隔
    %u              --> 无符号十进制整数
    %x,%X           --> 有符号十六进制整数
 */

/*
    %*              --> 滞后赋值(%*d)
    digit(s)        --> 最大字段宽度
                        达到最大字段宽度或遇到空白字符
    hh              --> 把整数读作signed char或unsigned char
                        示例: %lld   %llu
    h,l,L           --> %hd %hi 存储在 short int中
                        %hx %hu %ho  存储在 unsigned short int中
                        %ld %li  存储在 long 中
                        %lo %lx %lu 存储在unsigned long中
                        %le %lf %lg 存储在double中
                        %Le %Lf %Lg 存储在long double中
 */

/*
    通过指定足够大的固定字段宽度，让输出更加整齐
    printf("%9d %9d %9d\n", v1, v2, v3);
    printf("%.2f %10.2f", float_val, float_val);
 */

#include <stdio.h>

void b01_p078() {
    int v;
    char cs[40];
    float f;
    double d;

//    scanf("%d", &v);
//    printf("v is %d\n", v);
//    scanf("%d", &v);
//    printf("v is %d\n", v);
//
//    scanf("%s", cs);
//    printf("s is %s\n", cs);

    /*
        Ubuntu gcc
        输入：
            aabb（加回车）
        输出：
            v is 16711680
            v is 16711680
            s is aabb
            （注：16711680是0xFF0000）
     */


//    scanf("%f", &f);
//    printf("f is %f\n", f);
//
//    scanf("%lf", &d);
//    printf("d is %f\n", d);

    /*
        （输入）
        3.4E64
        （输出）
        f is inf
        （输入）
        3.4E64
        （输出）
        d is 34000000000000001601795228719991244580453667252880619983886876672.000000
     */

//    unsigned width, precision;
//    int number = 256;
//    double weight = 242.5;
//
//    printf("field width is:\n");
//    scanf("%d", &width);
//    printf("the number is: %*d\n", width, number);
//    printf("a new width and a new precision:\n");
//    scanf("%d %d", &width, &precision);
//    printf("weight is %*.*f\n", width, precision, weight);

    /*
        field width is:
        7
        the number is:     256
        a new width and a new precision:
        5   9
        weight is 242.500000000
     */

//    int n;
//    printf("input three integers:\n");
//    scanf("%*d %*d %d", &n);
//    printf("the last integer is %d\n", n);
    /*
        读取文件特定列的时候，非常有用
        input three integers:
        1 2 3
        1 2 3
        the last integer is 3
        Hello, World!
     */



}
