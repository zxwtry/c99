//
// Created by zxwtry on 2017/10/17.
//

#include <stdio.h>

void func(void);

void b01_p025() {
    printf("start b01_p25 function\n");
    func();
    printf("end b01_p25 function\n");
}

void func(void) {
    printf("in func function\n");
}