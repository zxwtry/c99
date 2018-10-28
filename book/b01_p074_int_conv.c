//
// Created by zxwtry on 17-10-21.
//


#include <stdio.h>

#define PAGES 336
#define WORDS 65618

void b01_p074() {
    short a = PAGES;
    short b = - PAGES;

    printf("by %%hd and %%hu is %hd  %hu\n", a, a);
    //by %hd and %hu is 336  336

    printf("by %%hd and %%hu is %hd  %hu\n", b, b);
    //by %hd and %hu is -336  65200

    printf("by %%c is %c   %c\n", a, b);
    //by %c is P   �

    printf("by %%d %%hd %%c is %d  %hd %c\n", WORDS, WORDS, WORDS);
    //by %d %hd %c is 65618  82 R
}
