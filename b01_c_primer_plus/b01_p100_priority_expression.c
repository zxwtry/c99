//
// Created by zxwtry on 2018/4/20.
//

/*
    x * y ++  是  (x) * (y ++)   而不是   (x*y) ++
 */


/*f
    表达式举例：
    4
    -6
    4+21
    a * (b + c / d) / 20
    q = 5 * 2
    x = ++ q % 3
    q > 3
    6+(c=3+8)

    每个表达式都是一个值
 */

/*
    副作用：发生赋值
    顺序点：分号，进入下一步前，所有副作用都被计算
 */


#include <stdio.h>

/*
    类型自动转换高到低：
    long double、double、float、unsigned long long、long long、
    unsigned long、long、unsigned int、int
    如果long和int具有相同大小时，unsigned int比long的级别更高
    char和short没有出现，因为已经提升到int或unsigned int

    以转换为char为例：
    用double，超过127，就是127
             小于-128，就是-128
    用int，就是取余。 mod 256
 */

void b01_p106_convert() {
    char ch;
    int i;
    float fl;

    fl = i = ch = 'A';
    printf("ch=%c, i=%d, fl=%2.2f\n", ch, i, fl);

    ch = ch + 1;
    i = fl + 2 * ch;
    fl = 2.0 * ch + i;
    printf("ch=%c, i=%d, fl=%2.2f\n", ch, i, fl);

    ch = -5212205.17;
    printf("ch=%d\n", (int)ch);
    ch = 5212205.17;
    printf("ch=%d\n", (int)ch);
    ch = -5.17;
    printf("ch=%d\n", (int)ch);
    ch = 5.17;
    printf("ch=%d\n", (int)ch);
    ch = 5212205;
    printf("ch=%d\n", (int)ch);
    ch = -5212205;
    printf("ch=%d\n", (int)ch);
    /*
        ch=A, i=65, fl=65.00
        ch=B, i=197, fl=329.00
        ch=-128
        ch=127
        ch=-5
        ch=5
        ch=45
        ch=-45
     */
}


void b01_p100() {
    b01_p106_convert();
}