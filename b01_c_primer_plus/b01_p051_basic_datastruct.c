//
// Created by zxwtry on 17-10-18.
//

/*
 *  基本数据类型有11个关键字：
 *      int         long        short
 *      unsigned    char        float
 *      double      signed      _Bool
 *      _Complex    _Imaginary
 */


#include <stdio.h>


void b01_p051() {
    printf("sizeof(int) is %zd\n", sizeof(int));
    printf("sizeof(char) is %zd\n", sizeof(char));
    printf("sizeof(short) is %zd\n", sizeof(short));
    printf("sizeof(long) is %zd\n", sizeof(long));
    printf("sizeof(long int) is %zd\n", sizeof(long int));
    printf("sizeof(long long) is %zd\n", sizeof(long long));
    printf("sizeof(float) is %zd\n", sizeof(float));
    printf("sizeof(double) is %zd\n", sizeof(double));
    printf("sizeof(long double) is %zd\n", sizeof(long double));
    printf("sizeof(_Bool) is %zd\n", sizeof(_Bool));
    printf("sizeof(_Complex) is %zd\n", sizeof(_Complex));

    int a = 1.23;       //只是警告，没有错误
    float b = 1.23;     //只是警告，没有错误
    char c = 1232342;   //只是警告，没有错误
    

    /*
        64bit  ubuntu  gcc 5.4.0

        sizeof(int) is 4
        sizeof(char) is 1
        sizeof(short) is 2
        sizeof(long) is 8
        sizeof(long int) is 8
        sizeof(long long) is 8
        sizeof(float) is 4
        sizeof(double) is 8
        sizeof(long double) is 16
        sizeof(_Bool) is 1
        sizeof(_Complex) is 16
     */

}
