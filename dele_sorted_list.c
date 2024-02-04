// Q: 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回已排序的链表 。
// 输入：head = [1,1,2]
// 输出：[1,2]

// 遍历链表，比较当前节点和它的下一个节点。如果它们的值相同，就删除下一个节点；否则，就移动到下一个节点。

// 检查链表是否为空。如果为空，直接返回。
// 遍历链表，对于每个节点，比较当前节点与下一个节点的值。
// 如果当前节点的值与下一个节点的值相同，删除下一个节点。
// 继续遍历直到链表末尾。


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
// 数据域 (val): 存储了链表节点的值或数据。
// 指针域 (next): 存储了指向链表中下一个节点的指针。

struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode *p = head;

    while(p!=0 && p->next!=0) {

        if (p->val == p->next->val) {
            // (*p).val
            struct ListNode *n = p->next;
            p->next = p->next->next;
            free(n);
        }
        else {
            p = p->next;
        }
    }
    return head;
}

struct ListNode* newNode (int val) {
    struct ListNode *node = (struct ListNode*) malloc (sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}


// 链表为空，新节点成为链表的第一个节点；如果链表非空，新节点被添加到链表的最后。
// 为了能够在函数内部修改原始指针本身，你需要传递一个指针的地址，即指向指针的指针。这样，函数就可以通过解引用这个指向指针的指针来修改原始指针的值。
// struct ListNode** head 允许函数直接修改调用者的头指针 head

void appendNode(struct ListNode** head, int val) {
    struct ListNode* addNode = newNode(val);
    if (*head == NULL) {
        *head = addNode;
    } else {
        struct ListNode* a = *head;
        while (a->next != NULL) {
            a = a->next;
        }
        a->next = addNode;
    }
}

void Outputlist(struct ListNode* head) {
    printf("[");
    while (head != NULL){
        printf("%d",head->val);
        if (head->next !=NULL) {
            printf(",");
        }
        head = head->next;
    }
    printf("]\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* f;
    while (head != NULL) {
        f = head;       
        head = head->next; 
        free(f);       
    }
}

int main() {

    struct ListNode* head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 1);
    appendNode(&head, 2);
    Outputlist(head);

    head = deleteDuplicates(head);
    Outputlist(head);

    freeList(head);
    return 0;
}
