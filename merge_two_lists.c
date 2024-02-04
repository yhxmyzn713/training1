// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]

// p p->next head tail
// .运算符用于直接访问结构体变量的成员 ->运算符用于访问指向结构体的指针所指对象的成员,


#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct  ListNode {
    int val;
    struct ListNode *next;
};

// Merge two singly-linked lists.
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    // create a dummy head
    struct ListNode dummy;
    dummy.next = NULL;                    // dummy 结构体变量
    struct ListNode* tail = &dummy;

    //compare two lists
    while (list1 != NULL && list2 != NULL) {

        if (list1->val < list2->val){
            tail->next = list1;
            list1 = list1->next;
        } 
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    // connect the remain value
    if (list1 !=NULL) {
        tail->next = list1;
    }
    else if (list2 != NULL) {
        tail->next = list2;
    }

    return dummy.next;             // dummy.next 将指向合并后的链表的第一个节点
}

// Definition a function for newnode
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc (sizeof(struct ListNode)); // (type*) malloc (size)
    node->val = val;
    node->next = NULL;
    return node; 
}

void Output(struct ListNode* head) {
    printf("[");
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf(",");
        }
        head = head->next;
    }
    printf("]\n");
}

// 释放内存, 以避免内存泄露
void freeList(struct ListNode* head) {
    struct ListNode* f;
    while (head != NULL) {
        f = head;       
        head = head->next; 
        free(f);       
    }
}



int main() {
    //  l1 = [1,2,4], l2 = [1,3,4]
    struct ListNode* list1 = newNode(1);
    list1->next = newNode(2);
    list1->next->next = newNode(4);

    struct ListNode* list2 = newNode(1);
    list2->next = newNode(3);
    list2->next->next = newNode(4);

    struct ListNode* merged = mergeTwoLists(list1, list2);
    Output(merged);
    freeList(merged);
    return 0;
}

