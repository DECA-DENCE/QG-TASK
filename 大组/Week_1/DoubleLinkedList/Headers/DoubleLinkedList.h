#ifndef _DoubleLinkedList_h_
#define _DoubleLinkedList_h_
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct DuLNode {
    ElemType data;
    struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;
typedef enum Status {
    error,
    success,
} Status;

//函数的声明
Status InitList_DuL(DuLinkedList* L);
void DestroyList_DuL(DuLinkedList* L);
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q);
Status DeleteList_DuL(DuLNode* p, ElemType* e);
void TraverseList_DuL(DuLinkedList L);
Status IsLoopList(DuLinkedList L);
Status ReverseList(DuLinkedList* L);

Status InitList_DuL(DuLinkedList* L) {
    DuLinkedList List;
    List = (DuLinkedList)malloc(sizeof(DuLNode));
    if (List == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    List->next = NULL;
    List->prior = NULL;
    *L = List;
    return success;
}

void DestroyList_DuL(DuLinkedList* L) {
    DuLinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
    if (p->next == NULL)//当链表为空时，直接连接p、q
    {
        p->next = q;
        q->prior = p;
    }
    else
    {
        DuLinkedList temp;
        temp = p->next;
        p->next = q;
        q->next = temp;
        temp->prior = q;
        q->prior = p;
        return success;
    }
}

Status DeleteList_DuL(DuLNode* p, ElemType* e) {
    if (p->next == NULL)
    {
        printf("链表为空，无法删除\n");
        return error;
    }
    else
    {
        DuLinkedList posNode = p->next, posNodeFront = p;
        //找到删除结点的位置
        while (posNode->data != *e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("找不到该数据\n");
                return error;
            }
        }
        if (posNode->next != NULL)
        {
            posNodeFront->next = posNode->next;
            posNode->next->prior = posNodeFront;
        }
        else
        {
            posNodeFront->next = NULL;
        }
        free(posNode);
        return success;
    }
}

void TraverseList_DuL(DuLinkedList L) {
    if (L == NULL)
    {
        printf("链表未创建，请先创建链表\n");
    }
    else if (L->next == NULL)
    {
        printf("当前链表为空\n");
    }
    else
    {
        DuLinkedList temp = L->next;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

Status IsLoopList(DuLinkedList L) {
    DuLinkedList fast = L, slow = L;
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

//递归
Status ReverseList(DuLinkedList* L) {
    DuLNode* newHead;		//储存每次反转后的第一个节点 
    DuLNode* p1;			//每次都指向前一个节点	
    DuLNode* p2;			// 储存未反转前的下一个节点 
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
void ReverseList(DuLinkedList L) {
    DuLinkedList cur,temp, prev;
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
#endif