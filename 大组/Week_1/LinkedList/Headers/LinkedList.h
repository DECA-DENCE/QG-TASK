#ifndef _LinkedList_h_
#define _LinkedList_h_
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode* next;
} LNode, * LinkedList;
typedef enum Status
{
    error,
    success
} Status;

//函数的声明
Status InitList(LinkedList* L);
void DestroyList(LinkedList* L);
Status InsertList(LNode* p, int data);
Status DeleteList(LNode* p, int e);
void TraverseList(LinkedList L);
Status SearchList(LinkedList L, int e);
Status ReverseList(LinkedList* L);
Status IsLoopList(LinkedList L);
Status Exchange(LinkedList* L);
LNode* FindMidNode(LinkedList L);

Status InitList(LinkedList* L) {
    LinkedList list;

    list = (LinkedList)malloc(sizeof(LNode));
    if (list == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    list->next = NULL;
    *L = list;

    return success;
}

void DestroyList(LinkedList* L) {
    LinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

Status InsertList(LNode* p, int data) {
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    newNode->data = data;
    newNode->next = NULL;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return success;
}

Status DeleteList(LNode* p, int e) {
    LinkedList posNode = p->next;
    LinkedList posNodeFront = p;
    if (posNode == NULL)
    {
        printf("链表为空，无法删除\n");
    }
    else
    {
        while (posNode->data != e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("没有该数据\n");
                return error;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
        return success;
    }
}

void TraverseList(LinkedList L) {
    LinkedList temp;

    temp = L->next;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Status SearchList(LinkedList L, int e) {
    while (L != NULL)
    {
        if (L->data == e)
        {
            return success;
        }
        L = L->next;
    }
    return error;
}

//递归
Status ReverseList(LinkedList* L) {
    LNode* newHead;		//储存每次反转后的第一个节点 
    LNode* p1;			//每次都指向前一个节点	
    LNode* p2;			// 储存未反转前的下一个节点 
    p1 = (*L)->next;
    p2 = p1->next;
    p1->next = NULL;
    newHead = p1;
    while (p2 != NULL) {
        p1 = p2;
        p2 = p1->next;
        p1->next = newHead;
        newHead = p1;
    }
    (*L)->next = newHead;
}

/*非递归
void ReverseList(LinkedList L) {
    LinkedList cur,temp, prev;
    cur = L->next;
    prev = NULL;
    while(cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    L->next = prev;
}
*/

Status IsLoopList(LinkedList L) {
    LinkedList fast = L, slow = L;
    while (fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if ((fast = fast->next->next) == NULL)
            return error;
        if (fast == slow)
            return success;
    }
    return error;
}

Status Exchange(LinkedList L) {
    LNode* p1;
    LNode* p2;
    LNode* p;    //p1为第一个节点，p和p2为第二个节点
    p1 = L->next;
    p = p2 = p1->next;

    while (p1->next != NULL && p1->next->next != NULL) {
        p1->next = p1->next->next;
        p1 = p1->next;

        if (p2->next != NULL && p2->next->next != NULL) {
            p2->next = p2->next->next;
            p2 = p2->next;
        }
    }
    p2->next = NULL;
    p1->next = p;

}

LNode* FindMidNode(LinkedList L) {
    LinkedList slow = L, fast = L;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
#endif