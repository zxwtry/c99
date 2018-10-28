//
// Created by zxwtry on 2017/10/17.
//


/*
 *  一般情况下：
 *      long long  -->  64位
 *      long       -->  32位
 *      short      -->  16位
 *      int        -->  16/32位
 */

/*
 *  数据结构范围：
 *      16位有符号：     -32768  到  32767
 *      32位有符号：     -2147483648  到  2147483647
 *      16位无符号：     0 到 65535
 *      32位无符号：     0 到 4294967295
 */

/*
 *  代码中的数字类型：
 *      l/L     -->    long
 *      ll/LL   -->    long long
 *      llu/LLU/ull/ULL   -->  unsigned long long
 */

/*
 *  printf数字打印：（格式说明符只能小写）
 *      unsiged int     -->   %u
 *      long            -->   %ld
 *      long十六进制     -->   %lx
 *      long八进制       -->   %lo
 *      short十进制      -->  %hd
 *      short八进制      -->  %ho
 *      unsigned long   -->  %lu
 *      long long       -->  %lld
 *      unsigned long long --> %llu
 */

#include <stdio.h>

void b01_p038(void) {
    int a = 100;
    printf("dec: %d   octal: %o   hex: %x\n", a, a, a);
    printf("dec: %d   octal: %#o   hex: %#x\n", a, a, a);
    int x = 2147483647;
    unsigned int y = 4294967295;
    printf("%d   %d   %d\n", x, x + 1, x + 2);
    printf("%u   %u   %u\n", y, y + 1, y + 2);

    /*
     *  输出：
        dec: 100   octal: 144   hex: 64
        dec: 100   octal: 0144   hex: 0x64
        2147483647   -2147483648   -2147483647
        4294967295   0   1
     */


}

