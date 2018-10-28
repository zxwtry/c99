//
// Created by xinweizhu on 2018/9/27.
//

#include <malloc.h>
#include <unistd.h>

/**
 *  程序退出之后，未释放的内存会被OS释放
 */
void p002() {
    const int XN = 10;
    const int YN = 10;
    int ** xArr = (int **) malloc(sizeof(int *) * XN);
    for (int i = 0; i < XN; i ++) {
        xArr[i] = (int *) malloc(sizeof(int) * YN);
    }
    usleep(1000 * 99999);
}

