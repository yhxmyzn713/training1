#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
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
    }
    else {
        printf("No such two number matched.\n");
    }
    return 0;
}