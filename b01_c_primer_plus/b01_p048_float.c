//
// Created by zxwtry on 17-10-18.
//

/*
 *  三种浮点数：
 *   f/F   float        32位    8位指数    24位非指数
 *         double       64位
 *   l/L   long double
 */

#include <stdio.h>

/*
 *  三种浮点数printf
 *  float           %f %e %a
 *  double          %f %e %a
 *  long double     %Lf  %Le  %La
 *
 *  printf传递float参数的时候，自动将float转成double
 */

/*
 *  浮点数的上溢和下溢
 *  上溢：overflow
 *      大到不能表达的数
 *      printf显示inf或infinity
 *  下溢：underflow
 *      指数已经到最小
 *      只能将尾数处理
 *      这样损失了精度
 */

/*
 *  NaN：Not-a-Number
 *      特殊浮点数
 *      例如：用于输入非法的情况
 *      asin()函数输入是不能大于1的，
 *      如果大于1，那么将返回NaN
 *
 *  等同于nan NAN等
 */



void b01_p048() {
    float a = 3200.0;
    double b = 3.2993;
    long double c = 2312;
    printf("%f, %e, %a\n", a, a, a);
    printf("%f, %e, %a\n", b, b, b);
    printf("%Lf, %Le, %La\n", c, c, c);
    /*
        3200.000000, 3.200000e+03, 0x1.9p+11
        3.299300, 3.299300e+00, 0x1.a64f765fd8adbp+1
        2312.000000, 2.312000e+03, 0x9.08p+8
     */
}

