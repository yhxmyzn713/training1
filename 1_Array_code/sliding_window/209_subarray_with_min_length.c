/* 长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组
 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
*/

#include <stdio.h>
#include <stdlib.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int i = 0, j = 0, sum=0, sum_len=0;
    int result = numsSize+1;

    for(j=0;j<numsSize;j++){
        sum += nums[j];

        while(sum>=target){
            sum_len = j-i+1;
            if(sum_len<result){
                result = sum_len;
            }
            sum = sum - nums[i];
            i++;
        }
    }
    if (result == numsSize+1){
        return 0;
    }
    else{
        return result;
    }
    
    
}

int main() {
    int target;
    scanf("%d", &target);
    int numsSize;
    scanf("%d", &numsSize); // 先读取数组大小
    int nums[numsSize]; // 根据读取的大小定义数组
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    int result = minSubArrayLen(target, nums, numsSize); // 直接传递numsSize而非其地址
    printf("%d\n", result); // 打印结果

    return 0;
}