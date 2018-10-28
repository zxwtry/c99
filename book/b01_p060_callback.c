//
// Created by zxwtry on 17-10-20.
//



#include <stdio.h>
#include <string.h>
/* string.h提供strlen()函数 */

#define DENSITY 62.4

void b01_p060() {
    float weight, volume;
    int size, letters;
    char name[40];

    printf("input your name\n");
    scanf("%s", name);

    printf("input your weight\n");
    scanf("%f", &weight);

    size = sizeof(name);
    volume = weight / DENSITY;
    letters = strlen(name);

    printf("your name has %d/%d letters\n", letters, size);
    printf("your volume is %f\n", volume);

    /*
        input your name
        jack
        input your weight
        100
        your name has 4/40 letters
        your volume is 1.602564
     */

}

