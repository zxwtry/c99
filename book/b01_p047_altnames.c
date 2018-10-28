//
// Created by zxwtry on 2017/10/18.
//

/*
 *  int16_t     16位有符号整数类型
 *  uint32_t    32位无符号整数类型
 *
 *  在头文件inttypes.h中
 */

#include <inttypes.h>
#include <stdio.h>

void b01_p047() {
    int16_t var16 = 1623;
    printf("by d is %d\n", var16);
    printf("by PRId16 is %" PRId16 "\n", var16);

    /*
        by d is 1623
        by PRId16 is 1623
     */


    int64_t var64 = 0x7fffffffffffffff;
    printf("by lld is %lld\n", var64);
    printf("by PRId64 is %" PRId64 "\n", var64);

    /*
        by lld is 9223372036854775807
        by PRId64 is 9223372036854775807
     */

    uint8_t var8 = 0xff;
    printf("by d is %d\n", var8);
    printf("by PRIu8 is %" PRIu8 "\n", var8);

    /*
        by d is 255
        by PRIu8 is 255
     */

}
