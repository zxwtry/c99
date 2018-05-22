//
// Created by zxwtry on 2018/5/21.
//

#include <malloc.h>
#include <stdio.h>
#include <mem.h>

// 写成了积水问题，留这吧。没有验证是否有问题
int L011_maxArea(int* height, int heightSize) {
    int maxIndex = 0;
    int index = 0;
    int sum = 0;
    int max = 0;
    for (index = 0; index < heightSize; ++index) {
        if (height[index] > height[maxIndex]) {
            maxIndex = index;
        }
    }
    for (index = 0;  index < maxIndex ; ++ index) {
        max = max < height[index] ? height[index] : max;
        sum += max - height[index];
    }
    max = 0;
    for (index = heightSize - 1; index > maxIndex; --index) {
        max = max < height[index] ? height[index] : max;
        sum += max - height[index];
    }
    return sum;
}


// 又理解出错，写成了内部最大矩形
int L011_02_maxArea(int* height, int heightSize) {
    // 在index需要知道的是
    // 从index-1到0，第一个小于height[index]的是哪个
    // 从index+1到heightSize-1，第一个小于height[index]的是哪个

    int * left = (int *) malloc(sizeof(int) * heightSize);
    int * right = (int *) malloc(sizeof(int) * heightSize);

    int index = 0;
    int leftIndex = 0;
    int rightIndex = 0;

    int ans = 0;
    int tmp = 0;

    for (index = 0; index < heightSize; ++ index) {
        for (leftIndex = index - 1; leftIndex > -1 ; --leftIndex) {
            if (height[leftIndex] < height[index]) {
                break;
            }
        }
        left[index] = leftIndex + 1;
        for (rightIndex = 0; rightIndex < heightSize; ++rightIndex) {
            if (height[rightIndex] < height[index]) {
                break;
            }
        }
        right[index] = rightIndex - 1;
    }

    for (index = 0; index < heightSize; ++index) {
        tmp = height[index] * (right[index] - left[index] + 1);
        ans = ans < tmp ? tmp : ans;
    }

    free(left);
    free(right);

    return ans;
}


// 二次查询一下，试试
// TLE
int L011_03_maxArea(int* height, int heightSize) {
    int i = 0;
    int j = 0;
    int ans = 0;
    int tmp = 0;
    for (i = 0; i < heightSize; ++i) {
        for (j = i + 1; j < heightSize; ++j) {
            tmp = height[i] < height[j] ? height[i] : height[j];
            tmp = tmp * (j - i);
            ans = ans > tmp ? ans : tmp;
        }
    }
    return ans;
}

// 二分查询
// 查找最左边，且比value大的index
int L011_04_binary_find_index_up(int* height, int * indexArray, int arrayIndex, int value) {
    int i = 0, j = arrayIndex - 1;
    int midValue = 0;
    int midIndex = 0;
    while (i < j) {
        midIndex = (i + j) / 2;
        midValue = height[indexArray[midIndex]];
        if (midValue < value) {
            i = midIndex + 1;
        } else {
            j = midIndex;
        }
    }
    return indexArray[i];
}


// 假设需要以index为一条边
// 两个必要条件
// 另外一条边是离index最远，且height比它高
// 从左到右，收集一个递增下标
// 接下来的每个，都找比当前index的最小递增下标
// AC 28ms 19.38 %，看这个排名，肯定还有O(N)的方法
int L011_04_maxArea(int* height, int heightSize) {
    int * indexArray = (int *) malloc(sizeof(int) * heightSize);
    int index = 0;
    int arrayIndex = 0;
    int selectIndex = 0;
    int ans = 0;
    int tmp = 0;
    // memset(indexArray , 0 ,sizeof(int) * heightSize);
    indexArray[arrayIndex ++] = 0;
    // 从左到右
    for (index = 1; index < heightSize; ++index) {
        if (height[index] > height[indexArray[arrayIndex - 1]]) {
            indexArray[arrayIndex ++] = index;
        } else {
            selectIndex = L011_04_binary_find_index_up(height, indexArray, arrayIndex, height[index]);
            if (height[selectIndex] >= height[index]) {
                tmp = height[index] * (index - selectIndex);
                ans = ans < tmp ? tmp : ans;
            }
        }
    }
    // memset(indexArray , 0 ,sizeof(int) * heightSize);
    arrayIndex = 0;
    indexArray[arrayIndex ++] = heightSize - 1;
    // 从右到左
    for (index = heightSize - 2; index > -1; --index) {
        if (height[index] > height[indexArray[arrayIndex - 1]])  {
            indexArray[arrayIndex ++] = index;
        } else {
            selectIndex = L011_04_binary_find_index_up(height, indexArray, arrayIndex, height[index]);
            if (height[selectIndex] >= height[index]) {
                tmp = height[index] * (selectIndex - index);
                ans = ans < tmp ? tmp : ans;
            }
        }
    }
    free(indexArray);
    return ans;
}

// 这是discuss中的方法，非常巧妙
// AC 12ms 33.33 %
int L011_05_maxArea(int* height, int heightSize) {
    int ans = 0, tmp = 0, h = 0;
    int *i = height, *j = i + heightSize - 1;
    while (i < j) {
        h = *i < *j ? *i : *j;
        tmp = h * (j - i);
        ans = ans < tmp ? tmp : ans;
        while (*i <= h && i < j) i ++;
        while (*j <= h && i < j) j --;
    }
    return ans;
}

void L011() {
    int height[] = {1, 2, 4, 3};
    int heightSize = 4;
    printf("ans is %d\n", L011_05_maxArea(height, heightSize));
}