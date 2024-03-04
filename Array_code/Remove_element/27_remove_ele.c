/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1：

输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
*/

#include <stdlib.h>
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int slow = 0, fast = 0;

    for (fast=0; fast < numsSize; fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    //printf("%d\n", slow); // 这将打印出数组中元素的数量
    
    return slow;
}

int main() {
    int nums[]={3,2,2,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int val = 2;
    int newLength = removeElement(nums, numsSize, val);
    printf("New length: %d\n", newLength);
    printf("Modified array: [");
    for (int i = 0; i < newLength; i++) {
        if (i > 0) {
            printf(", "); // 在元素之间添加逗号和空格，除了第一个元素外
        }
        printf("%d", nums[i]); // 打印修改后的数组元素
    }
    printf("]\n");

    return 0;

}