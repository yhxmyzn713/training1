/*
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。

输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
*/

#include <stdlib.h>
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0; // 处理空数组的情况

    int slow = 1; // 从索引1开始，因为第一个元素总是独特的

    for (int fast = 1; fast < numsSize; fast++) {
        if (nums[fast] != nums[fast - 1]) {
            nums[slow++] = nums[fast];
        }
    }
    return slow; // 返回新的数组长度
}

int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = removeDuplicates(nums, numsSize);
    printf("%d\n",result);
    for (int i=0; i<result;i++) {
        printf("%d",nums[i]);
    }

}
