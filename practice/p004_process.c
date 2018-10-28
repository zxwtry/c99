//
// Created by xinweizhu on 2018/9/1.
//

#include <sys/param.h>
#include <unistd.h>
#include <stdio.h>

void p004() {
    pid_t p = fork();
    if (p > 0) {

    } else {

    }
    printf("%d", p);
}