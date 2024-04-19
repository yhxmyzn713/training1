/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。
示例 1：
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <stdio.h>
#include <stdlib.h>

int* path;
int pathTop;
int** ans;
int ansTop;

void backtracking(int n, int k,int startIndex) {
    //当path中元素个数为k个时，我们需要将path数组放入ans二维数组中
    if(pathTop == k) {
        //path数组为我们动态申请，若直接将其地址放入二维数组，path数组中的值会随着我们回溯而逐渐变化
        //因此创建新的数组存储path中的值
        int* temp = (int*)malloc(sizeof(int) * k);
        int i;
        for(i = 0; i < k; i++) {
            temp[i] = path[i];
        }
        ans[ansTop++] = temp;
        return ;
    }

    int j;
    for(j = startIndex; j <=n ;j++) {
        //将当前结点放入path数组
        path[pathTop++] = j;
        //进行递归
        backtracking(n, k, j + 1);
        //进行回溯，将数组最上层结点弹出
        pathTop--;
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    //path数组存储符合条件的结果
    path = (int*)malloc(sizeof(int) * k);
    //ans二维数组存储符合条件的结果数组的集合。（数组足够大，避免极端情况）
    ans = (int**)malloc(sizeof(int*) * 10000);
    pathTop = ansTop = 0;

    //回溯算法
    backtracking(n, k, 1);
    //最后的返回大小为ans数组大小
    *returnSize = ansTop;
    //returnColumnSizes数组存储ans二维数组对应下标中一维数组的长度（都为k）
    *returnColumnSizes = (int*)malloc(sizeof(int) *(*returnSize));
    int i;
    for(i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    //返回ans二维数组
    return ans;
}

// 剪枝：
int* path;
int pathTop;
int** ans;
int ansTop;

void backtracking(int n, int k,int startIndex) {
    //当path中元素个数为k个时，我们需要将path数组放入ans二维数组中
    if(pathTop == k) {
        //path数组为我们动态申请，若直接将其地址放入二维数组，path数组中的值会随着我们回溯而逐渐变化
        //因此创建新的数组存储path中的值
        int* temp = (int*)malloc(sizeof(int) * k);
        int i;
        for(i = 0; i < k; i++) {
            temp[i] = path[i];
        }
        ans[ansTop++] = temp;
        return ;
    }

    int j;
    for(j = startIndex; j <= n- (k - pathTop) + 1;j++) {
        //将当前结点放入path数组
        path[pathTop++] = j;
        //进行递归
        backtracking(n, k, j + 1);
        //进行回溯，将数组最上层结点弹出
        pathTop--;
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    //path数组存储符合条件的结果
    path = (int*)malloc(sizeof(int) * k);
    //ans二维数组存储符合条件的结果数组的集合。（数组足够大，避免极端情况）
    ans = (int**)malloc(sizeof(int*) * 10000);
    pathTop = ansTop = 0;

    //回溯算法
    backtracking(n, k, 1);
    //最后的返回大小为ans数组大小
    *returnSize = ansTop;
    //returnColumnSizes数组存储ans二维数组对应下标中一维数组的长度（都为k）
    *returnColumnSizes = (int*)malloc(sizeof(int) *(*returnSize));
    int i;
    for(i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    //返回ans二维数组
    return ans;
}

