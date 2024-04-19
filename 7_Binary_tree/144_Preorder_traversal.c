/*
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
输入：root = [1,null,2,3]
输出：[1,2,3]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void Traversal(struct TreeNode* root,int *returnNum,int* returnSize )
{
    if(root==NULL)
    {
        return; 
    }

    //根
    returnNum[*returnSize]   = root-> val;       
    *returnSize = *returnSize + 1;

    //左
    Traversal(root->left,returnNum,returnSize);

    //右
    Traversal(root->right,returnNum,returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    //树中节点数目在范围 [0, 100] 内
    int *returnNum = (int *)malloc(sizeof(int)*101);
    *returnSize = 0;
    if(root == NULL)
    {
        return NULL;
    }
    Traversal(root,returnNum,returnSize);
    return returnNum;
}


