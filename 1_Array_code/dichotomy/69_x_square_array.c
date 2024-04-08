/* 
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
*/



#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x) {
    int left = 0, right = x, middle = 0, ans = -1;

    while (left <= right) {
        middle = left + (right - left)/2;
        
        // 使用 long long 类型避免乘法溢出
        //long long square = (long long)middle * middle;

        if ((long long)middle * middle <= x ) {
            left = middle +1;
            ans = middle;
        }
        else {
            right = middle -1;
        }
    }

    return ans;
}