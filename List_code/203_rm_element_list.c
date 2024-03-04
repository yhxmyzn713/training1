// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回新的头节点 。
// 输入：head = [1,2,6,3,4,5,6], val = 6
// 输出：[1,2,3,4,5]

// 删除头节点中满足条件的节点：首先检查头节点（head）是否满足删除条件。如果是，更新头节点指针到下一个节点，并释放原头节点。重复此步骤直到头节点的值不等于 val。
// 删除链表中间满足条件的节点：遍历链表，使用两个指针：prev（指向当前节点的前一个节点）和 current（当前遍历到的节点）。如果 current 节点需要被删除，就将 pre->next 更新为 current->next，然后释放 current 节点，以此来维护链表的连续性。
// 在处理链表删除操作时，特别是删除所有满足特定条件的节点时，先考虑删除头节点的原因主要是头节点的特殊性质。头节点没有前一个节点，这使得它的删除操作与链表中间或尾部节点的删除操作略有不同。
// 通过添加一个哑节点（dummy node）作为链表的新头节点，可以进一步简化这一逻辑。哑节点本身永远不会被删除，它的下一个节点指向原链表的头节点。这样，原头节点的删除就与中间节点的删除无异，从而可以用一个统一的逻辑来处理所有节点的删除操作。这种方法既处理了头节点可能需要被删除的问题，也避免了在删除过程中需要不断更新头节点指针的复杂性。


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// 删除链表中所有值等于val的节点的函数
struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *pre = dummy, *current = head;

    while (current != NULL) {

        if (current->val == val) {
            pre->next = current->next;
            free(current);
            current = pre->next; 
        } 
        else {
            pre = current;
            current = current->next;
        }
    }

    head = dummy->next;
    free(dummy); 
    return head;
}

struct ListNode* newNode (int val) {
    struct ListNode *node = (struct ListNode*) malloc (sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void appendNode(struct ListNode** head,int val) {
    struct ListNode* addNode = newNode(val);
    if (*head == NULL) {
        *head = addNode;
    }

    else {
        struct ListNode* temp= *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = addNode;
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
    appendNode(&head, 2);
    appendNode(&head, 6);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    appendNode(&head, 6);
    Outputlist(head);

    head = removeElements(head,6);
    Outputlist(head);
    freeList(head);
    return 0;
}