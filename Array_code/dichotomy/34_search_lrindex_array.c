/**
 * Note: The returned array must be malloced, assume caller calls free().
 
 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。如果数组中不存在目标值 target，返回 [-1, -1]。
 示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]


目标是找到目标值的最左和最右索引。
1. 找到唯一目标值的位置时：middle=left=right，但存在很多目标值的时候，找到nums[middle]=target的时候，right>=left。
2. 此时寻找最左索引意味着，查看再左一位的值是否=target，不断区间变化后，直到middle=left=right，找到最左边界，ans=middle。
函数判断条件包括 nums[mid] >= target，这样可以确保即使遇到相等的情况也会向左侧（较小的索引方向）收缩搜索范围，从而找到目标值的最左边索引。
3. 此时寻找最右索引意味着，只在nums[middle]>target更新ans，和不断右移区间，这样就会引导Left_index->right_index，即middle指向最右边target的下一位。
函数的判断条件仅为 nums[mid] > target，这样当找到目标值时，会继续向右侧（较大的索引方向）探索，以确定目标值在数组中出现的最后位置。

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int search(int* nums, int numsSize, int target, bool lower) {
    int left = 0, right = numsSize-1, middle = 0, ans = numsSize;
    
    while (left<=right) {
        middle = left + (right - left)/2;

        if (nums[middle] > target || (lower && nums[middle]>=target)) {
            right = middle-1;
            //ans = middle;
        }
        else {
            left = middle+1;
        }
    }
    return middle;
} 

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int left_index = search(nums, numsSize, target, true);
    int right_index = search(nums, numsSize, target, false)-1;
     *returnSize = 2;
    int *result = malloc(sizeof(int)*2);

    if (left_index <= right_index && right_index < numsSize && nums[left_index] == target && nums[right_index] == target) {
        result[0] = left_index, result[1] = right_index;
        return result;
    }
    result[0] = -1, result[1] = -1;
    return result;

}

int main() {
    int nums[] = {5,7,7,8,8,8,8,8,10};
    int target = 8;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *result = searchRange(nums, numsSize, target, &returnSize);
    printf("%d [%d, %d]\n", target, result[0], result[1]);
    return 0;
}




/*
searchRange 函数的设计是返回一个指向整数数组的指针（int*），因此正确的接收返回值的方式是使用一个指针变量来接收它
int *result = searchRange(nums, numsSize, target, &returnSize);
这里，returnSize 是通过指针传递的，因为函数需要修改 returnSize 的值以反映返回的数组的大小。这是为了让调用者知道返回的数组有多大。因此，returnSize 本身作为一个整数（int 类型）被声明，但在传递给函数时，使用 &returnSize 来传递它的地址，使得 searchRange 函数能够修改 returnSize 变量本身的值。

如果某个函数（假设它也叫 searchRange，但与您提供的函数不同）设计为返回一个单一的整数值（int），而不是一个指针，那么您将使用一个普通的整数变量来接收这个返回值，
int result = searchRange(nums, numsSize, target, &returnSize);
这里，即使函数返回的是一个整数而不是指针，returnSize 仍然可以通过地址传递（即 &returnSize），如果这个函数设计为需要修改 returnSize。


总结
当函数返回类型是指针（int*）时，使用指针变量接收返回值。
当函数返回类型是整数（int）时，使用整数变量接收返回值。
如果函数需要修改一个参数的值并让这个修改反映到调用者那里，该参数应通过其地址传递，无论函数返回什么类型的值。
*/