//
// Created by xinweizhu on 2018/9/1.
//


#include <pthread.h>
#include <stdio.h>

void p003_thread01_thread(void * arg) {
    int i = *(int*) arg;
    pthread_t self = pthread_self();
    printf("[%d] is thread: %d\n", self, i);
    pthread_exit(NULL);
}

void p003() {
    pthread_t t;
    for (int i = 0; i < 5; i ++) {
        pthread_create(&t, NULL, (void *) p003_thread01_thread, (void *) &i);
        printf("pthread_create i:%d  t:%d\n", i, t);
        pthread_join(t, NULL);
        printf("pthread_join  i:%d\n", t);
    }
}
