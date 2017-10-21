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

#include <stdio.h>

void b01_p078() {
    int v;
    char cs[40];

    scanf("%d", &v);
    printf("v is %d\n", v);

    scanf("%s", cs);
    printf("s is %s\n", cs);

}
