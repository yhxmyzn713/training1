#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test() {
    int result = 6;

    printf("result = %d\n", result);

    int result_1[3];
    memset(&result_1, '1', sizeof(result));

    printf("%d %d %d\n", result_1[0], result_1[1], result_1[2]);

    int *p = result_1;

    printf("%d %d\n", p[1], result_1[1]); 
}

//----------------------------//

int* result = NULL;

int twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;

    result=malloc(2*sizeof(int));
    if (result == NULL) {
        printf("no memory");
        return -1;
    }

    for (i=0;i<numsSize;i++){
        for (j=i+1;j<numsSize;j++){
            if (nums[i]+nums[j]==target){
                result[0]=i;
                result[1]=j;
                *returnSize=2;
                return 0;
            }
        }
    }
    *returnSize=0;

    return 0; 
}

int main() {
    int nums[] = {2,7,11,15};
    int target=9;
    int returnSize;

    int twosum_result = twoSum(nums,sizeof(nums)/sizeof(nums[0]),target,&returnSize);
    if (twosum_result != 0) {
        printf("No such two number matched.\n");

        return -1;
    }

    if (result != NULL){
        printf("Indices:[%d,%d]\n",result[0],result[1]);

        free(result);
        result = NULL;
    }

    return 0;
}