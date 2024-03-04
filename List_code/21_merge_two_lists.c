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

    struct ListNode* temp_list1 = list1;
    struct ListNode* temp_list2 = list2;

    // create a dummy head
    struct ListNode dummy;
    dummy.next = NULL;                    // dummy 结构体变量
    struct ListNode* tail = &dummy;

    //compare two lists
    while (temp_list1 != NULL && temp_list2 != NULL) {
        
        if (temp_list1->val < temp_list2->val){
            tail->next = temp_list1;
            temp_list1 = temp_list1->next;
        } 
        else {
            tail->next = temp_list2;
            temp_list2 = temp_list2->next;
        }
        tail = tail->next;
    }
    
    // connect the remain value
    if (temp_list1 !=NULL) {
        tail->next = temp_list1;
    }
    else if (temp_list2 != NULL) {
        tail->next = temp_list2;
    }
    printf("%d\n", list1->next->next->val);

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
    struct ListNode* example1 = newNode(1);
    example1->next = newNode(2);
    example1->next->next = newNode(4);

    struct ListNode* example2 = newNode(1);
    example2->next = newNode(3);
    example2->next->next = newNode(4);

    printf("%d\n", example1->next->next->val);

    struct ListNode* merged = mergeTwoLists(example1, example2);
    Output(merged);
    freeList(merged);
    return 0;
}

