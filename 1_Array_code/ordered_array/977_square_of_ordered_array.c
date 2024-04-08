/* 
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
*/

#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    * returnSize = numsSize;
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    int index = numsSize-1;
    
    for (int i=0,j=numsSize-1;i<=j;index--){
        int square_i = nums[i] * nums[i];
        int square_j = nums[j] * nums[j];
        if (square_i > square_j){
            ans[index] = square_i;
            i++;
        }
        else{
            ans[index] = square_j;
            j--;
        }  
    }
    return ans;
}

int main(){
    int nums[] = {-4,-1,0,3,10};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int *result = sortedSquares(nums,numsSize, &returnSize);
    printf("[");
    for(int i=0;i<numsSize;i++){
        printf("%d ", result[i]);
    }
    printf("]");
    return 0;


}