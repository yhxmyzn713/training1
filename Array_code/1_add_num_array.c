// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那两个整数，并返回它们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。你可以按任意顺序返回答案。

// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]

#include <stdio.h>
#include <stdlib.h>

int twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;

    int* result=malloc(2*sizeof(int));
    for (i=0;i<numsSize;i++){
        for (j=i+1;j<numsSize;j++){
            if (nums[i]+nums[j]==target){
                result[0]=i;
                result[1]=j;
                *returnSize=2;
                return result;
            }
        }
    }
    *returnSize=0;

    return NULL; 
}

int main() {
    int nums[] = {2,7,11,15};
    int target=9;
    int returnSize;
    int* indices = twoSum(nums,sizeof(nums)/sizeof(nums[0]),target,&returnSize);
    if (indices != NULL) {
        printf("Indices:[%d,%d]\n",indices[0],indices[1]);
        free(indices);
        indices=NULL;
    }
    else {
        printf("No such two number matched.\n");
    }
    return 0;
}