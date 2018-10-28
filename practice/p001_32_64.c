//
// Created by xinweizhu on 2018/9/2.
//

#include <stdio.h>
#include <memory.h>
#include <malloc.h>

/**
 *  类型的长度
 *  char, short, int, long, long long, float, double, long double
 */
void p001_sizeof_basic() {
    printf("sizeof char is %zu\n", sizeof(char));
    printf("sizeof short is %zu\n", sizeof(short));
    printf("sizeof int is %zu\n", sizeof(int));
    printf("sizeof long is %zu\n", sizeof(long));
    printf("sizeof long long is %zu\n", sizeof(long long));
    printf("sizeof float is %zu\n", sizeof(float));
    printf("sizeof double is %zu\n", sizeof(double));
    printf("sizeof long double is %zu\n", sizeof(long double));
    /*
        sizeof char is 1
        sizeof short is 2
        sizeof int is 4
        sizeof long is 8
        sizeof long long is 8
        sizeof float is 4
        sizeof double is 8
        sizeof long double is 16
     */
}


/**
 *  指针长度
 */
void p001_sizeof_pointer() {
    printf("sizeof int* is %zu\n", sizeof(int*));
    printf("sizeof long double* is %zu\n", sizeof(long double*));
    /*
        sizeof int* is 8
        sizeof long double* is 8
     */
}


/**
 *  初始化一个数组，然后sizeof
 */
void p001_sizeof_array() {
    int arr1[] = {1, 2, 3, 4, 5};
    long double arr2[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    char arr3[] = {'1', '2', '3', '4', '5'};
    char *arr4 = "123456789";
    char *arr5 = "12345";
    printf("sizeof arr1 is %zu\n", sizeof(arr1));
    printf("sizeof arr2 is %zu\n", sizeof(arr2));
    printf("sizeof arr3 is %zu\n", sizeof(arr3));
    printf("sizeof arr4 is %zu  strlen arr4 is %zu\n", sizeof(arr4), strlen(arr4));
    printf("sizeof arr5 is %zu  strlen arr5 is %zu\n", sizeof(arr5), strlen(arr5));
    /*
        sizeof arr1 is 20
        sizeof arr2 is 80
        sizeof arr3 is 5
        sizeof arr4 is 8  strlen arr4 is 9
        sizeof arr5 is 8  strlen arr5 is 5
     */
}


/**
 *  malloc基本类型数组，然后sizeof
 */
void p001_sizeof_malloc_int() {
    int numsSize = 100;
    int *nums1 = (int *) malloc(sizeof(int) * numsSize);
    long double *nums2 = (long double *) malloc(sizeof(long double) * numsSize);
    printf("sizeof nums1 is %zu\n", sizeof(nums1));
    printf("sizeof nums2 is %zu\n", sizeof(nums2));
    free(nums1);
    free(nums2);
    /*
        sizeof nums1 is 8
        sizeof nums2 is 8
     */
}


/**
 *  定义一个结构体，然后sizeof
 */

struct p001_struct_00 {

};

struct p001_struct_00_01 {
    char c;
};

struct p001_struct_00_02 {
    char c1;
    char c2;
};

struct p001_struct_01 {
    char c;
    int i;
};

struct p001_struct_01_01 {
    char c;
    int i;
    long double l;
};

struct p001_struct_02 {
    struct p001_struct_01 s01;
};

struct p001_struct_03 {
    struct p001_struct_01 * s01;
};

struct p001_struct_04 {
    int s[99];
};

struct p001_struct_05 {
    struct p001_struct_01_01 s01;
    int s;
    int arr[55];
};

void p001_struct() {
    printf("sizeof struct p001_struct_00 is %zu\n", sizeof(struct p001_struct_00));
    printf("sizeof struct p001_struct_00_01 is %zu\n", sizeof(struct p001_struct_00_01));
    printf("sizeof struct p001_struct_00_02 is %zu\n", sizeof(struct p001_struct_00_02));
    printf("sizeof struct p001_struct_00 * is %zu\n", sizeof(struct p001_struct_00 *));
    printf("sizeof struct p001_struct_01 is %zu\n", sizeof(struct p001_struct_01));
    printf("sizeof struct p001_struct_01_01 is %zu\n", sizeof(struct p001_struct_01_01));
    printf("sizeof struct p001_struct_02 is %zu\n", sizeof(struct p001_struct_02));
    printf("sizeof struct p001_struct_03 is %zu\n", sizeof(struct p001_struct_03));
    printf("sizeof struct p001_struct_04 is %zu\n", sizeof(struct p001_struct_04));
    printf("sizeof struct p001_struct_05 is %zu\n", sizeof(struct p001_struct_05));
    /*
        sizeof struct p001_struct_00 is 0
        sizeof struct p001_struct_00_01 is 1
        sizeof struct p001_struct_00_02 is 2
        sizeof struct p001_struct_00 * is 8
        sizeof struct p001_struct_01 is 8
        sizeof struct p001_struct_01_01 is 32
        sizeof struct p001_struct_02 is 8
        sizeof struct p001_struct_03 is 8
        sizeof struct p001_struct_04 is 396
        sizeof struct p001_struct_05 is 256   =   32 + 4 * 56
     */
}



void p001() {
    p001_struct();
}