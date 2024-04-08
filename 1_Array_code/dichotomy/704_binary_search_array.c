/*给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
示例 1: 输入: nums = [-1,0,3,5,9,12], target = 9 输出: 4 */



#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize-1;
    int middle = 0;
    
    while (left<=right) {
        //middle = (left+right)/2;
        middle = left + (right - left)/2;

        if (nums[middle] > target) {
            right = middle-1;
        }

        else if (nums[middle] < target){
            left = middle+1;
        }

        else if (nums[middle] == target){
            return middle;
        }
    }
    return -1;
}

int main() {
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int numberSize = sizeof(nums) / sizeof(nums[0]);
    int result = search(nums, numberSize, target);
    if (result != -1) {
        printf("目标值 %d 的下标是: %d\n", target, result);
    } else {
        printf("目标值 %d 不存在于数组中\n", target);
    }
    return 0;
}


