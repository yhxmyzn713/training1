/*给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
输入：num = 16
输出：true */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPerfectSquare(int num) {
    int left = 0, right = num, middle = 0;

    while (left <= right) {
        middle = left + (right - left)/2;

        if ((long long)middle * middle < num) {
            left = middle +1;
        }
        else if ((long long)middle * middle > num) {
            right = middle -1;
        }
        else {
            return true;
        }    
    }
    return false;
}


