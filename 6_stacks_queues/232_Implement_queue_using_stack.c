/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：

你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 

示例 1：

输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
1.两个type为int的数组（栈），大小为100
    第一个栈stackIn用来存放数据，第二个栈stackOut作为辅助用来输出数据
2.两个指针stackInTop和stackOutTop，分别指向栈顶
*/
typedef struct {
    int stackInTop, stackOutTop;
    int stackIn[100], stackOut[100];
} MyQueue;

/*
1.开辟一个队列的大小空间
2.将指针stackInTop和stackOutTop初始化为0
3.返回开辟的队列
*/
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stackInTop = 0;
    queue->stackOutTop = 0;
    return queue;
}

/*
将元素存入第一个栈中,存入后栈顶指针+1
*/
void myQueuePush(MyQueue* obj, int x) {
    obj->stackIn[(obj->stackInTop)++] = x;
}

/*
1.若输出栈为空且当第一个栈中有元素（stackInTop>0时），将第一个栈中元素复制到第二个栈中（stackOut[stackTop2++] = stackIn[--stackTop1])
2.将栈顶元素保存
3.当stackTop2>0时，将第二个栈中元素复制到第一个栈中(stackIn[stackTop1++] = stackOut[--stackTop2])
*/
int myQueuePop(MyQueue* obj) {
    //优化：复制栈顶指针，减少对内存的访问次数
    int stackInTop = obj->stackInTop;
    int stackOutTop = obj->stackOutTop;
    //若输出栈为空
    if(stackOutTop == 0) {
        //将第一个栈中元素复制到第二个栈中
        while(stackInTop > 0) {
            obj->stackOut[stackOutTop++] = obj->stackIn[--stackInTop];
        }
    }
    //将第二个栈中栈顶元素（队列的第一个元素）出栈，并保存
    int top = obj->stackOut[--stackOutTop];
    //将输出栈中元素放回输入栈中
    while(stackOutTop > 0) {
        obj->stackIn[stackInTop++] = obj->stackOut[--stackOutTop];
    }
    //更新栈顶指针
    obj->stackInTop = stackInTop;
    obj->stackOutTop = stackOutTop;
    //返回队列中第一个元素
    return top;
}

//返回输入栈中的栈底元素
int myQueuePeek(MyQueue* obj) {
    return obj->stackIn[0];
}

//若栈顶指针均为0，则代表队列为空
bool myQueueEmpty(MyQueue* obj) {
    return obj->stackInTop == 0 && obj->stackOutTop == 0;
}

//将栈顶指针置0
void myQueueFree(MyQueue* obj) {
    obj->stackInTop = 0;
    obj->stackOutTop = 0;
}

