/*
给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
1 2 3
8 9 4
7 6 5
*/

/*

动态分配二维数组：首先，为矩阵matrix动态分配内存。这是通过为每一行分配一个指针数组，然后为每一行分配一个整数数组来实现的。
设置返回大小和列大小：通过*returnSize返回矩阵的大小（这里为n），并通过*returnColumnSizes数组返回每行的列数（对于正方形矩阵，每行的列数同样为n）。
生成螺旋矩阵：通过一个while循环来填充矩阵。每一次循环填充矩阵的外围一圈，然后调整start_x和start_y以及offset为下一圈的填充做准备。这个过程一直重复，直到loop次循环完成。
处理奇数n的情况：如果n是奇数，那么矩阵的中心会有一个未被填充的元素。通过简单地将count的当前值赋给这个元素来填充它。
打印矩阵：在main函数中，生成的矩阵被打印出来。
释放内存：最后，分配给矩阵和returnColumnSizes的内存被释放，以避免内存泄漏。

*/



#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int start_x = 0, start_y = 0; // 起始点
    int offset = 1, count = 1, loop = n/2; // offset用于控制每一圈的长度，count用于填充数字
    int i, j;

    // 动态分配二维数组
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // 设置returnSize和returnColumnSizes
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }

    // 生成螺旋矩阵
    while (loop--) {
        for (j = start_y; j < n - offset; j++) {
            matrix[start_x][j] = count++;
        }
        for (i = start_x; i < n - offset; i++) {
            matrix[i][j] = count++;
        }
        for (; j > start_y; j--) {
            matrix[i][j] = count++;
        }
        for (; i > start_x; i--) {
            matrix[i][j] = count++;
        }
        start_x++;
        start_y++;
        offset += 1;
    }

    // 对于奇数n，填充中心点
    if (n % 2 == 1) {
        matrix[n / 2][n / 2] = count;
    }

    return matrix;
}

int main() {
    int n = 3;
    int returnSize;
    int* returnColumnSizes;
    int** matrix = generateMatrix(n, &returnSize, &returnColumnSizes);

    // 打印矩阵
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(returnColumnSizes);

    return 0;
}