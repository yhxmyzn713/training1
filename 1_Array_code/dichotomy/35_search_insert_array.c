/* 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。 */

#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize -1;
    int middle = 0;

    while (left <= right) {
        middle = left + (right-left)/2;

        if (nums[middle] > target) {
            right = middle - 1; 
        }
        else if (nums[middle] < target) {
            left = middle + 1;
        }
        else if (nums[middle] == target) {
            return middle;
        }
    }
    return left;
}

int main() {
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int target = 8;
    int numberSize = sizeof(nums) / sizeof(nums[0]);
    int result = searchInsert(nums, numberSize, target);
    printf("%d %d\n", target, result);
    return 0;
}