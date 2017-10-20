//
// Created by zxwtry on 17-10-20.
//


/*
 *  #define VAL 233
 *  注意没有等于号
 *
 *  const val = 233;
 *  不能再修改了
 *
 *  limits.h和float.h提供整数类型和浮点数类型大小限制
 */


#include <stdio.h>
#include <limits.h>
#include <float.h>

void b01_p064() {
    printf("INT_MAX is %d\n", INT_MAX);
    printf("INT_MIN is %d\n", INT_MIN);

    printf("UINT_MAX is %ud\n", UINT_MAX);

    printf("FLT_MANT_DIG float类型的尾数位数 is %f\n", (double)FLT_MANT_DIG);
    printf("FLT_DIG float类型的最少有效数字位数（十进制） is %f\n", FLT_DIG);

    printf("FLT_MAX_10_EXP 带有全部有效数字的float类型的负指数的最小值（10为底） is %f\n", FLT_MAX_10_EXP);
    printf("FLT_MIN_10_EXP 带有全部有效数字的float类型的正指数的最大值（10为底） is %f\n", FLT_MIN_10_EXP);

    printf("FLT_MAX 保留全部精度的float类型正数的最大值 is %f\n", FLT_MAX);
    printf("FLT_MIN 保留全部精度的float类型正数的最小值 is %f\n", FLT_MIN);

    printf("FLT_EPSILON 1.00和比1.00大的最小的float类型值之间的差值 is %f\n", FLT_EPSILON);

    /*
        INT_MAX is 2147483647
        INT_MIN is -2147483648
        UINT_MAX is 4294967295d
        FLT_MANT_DIG float类型的尾数位数 is 24.000000
        FLT_DIG float类型的最少有效数字位数（十进制） is 24.000000
        FLT_MAX_10_EXP 带有全部有效数字的float类型的负指数的最小值（10为底） is 24.000000
        FLT_MIN_10_EXP 带有全部有效数字的float类型的正指数的最大值（10为底） is 24.000000
        FLT_MAX 保留全部精度的float类型正数的最大值 is 340282346638528859811704183484516925440.000000
        FLT_MIN 保留全部精度的float类型正数的最小值 is 0.000000
        FLT_EPSILON 1.00和比1.00大的最小的float类型值之间的差值 is 0.000000
     */

}
