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

}
