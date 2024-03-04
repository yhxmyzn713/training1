/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
*/

#include <stdlib.h>
#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int fast=0,slow=0;

    for(fast=0; fast<numsSize; fast++) {
        if (nums[fast] != 0) {
            nums[slow++] = nums[fast];
        }
    }
    
    for (fast=slow;fast<numsSize;fast++){
        nums[fast] = 0;
    }
}

int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    
    // 直接调用 moveZeroes，不尝试获取返回值
    moveZeroes(nums, numsSize);

    printf("[");
    for (int i = 0; i < numsSize; i++) {
        if (i > 0) {
            printf(", "); 
        }
        printf("%d", nums[i]); 
    }
    printf("]\n");
    return 0;
}