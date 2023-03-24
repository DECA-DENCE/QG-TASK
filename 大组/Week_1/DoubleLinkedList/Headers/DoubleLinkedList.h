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

//����������
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
        printf("�ڴ����ʧ��\n");
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
    if (p->next == NULL)//������Ϊ��ʱ��ֱ������p��q
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
        printf("����Ϊ�գ��޷�ɾ��\n");
        return error;
    }
    else
    {
        DuLinkedList posNode = p->next, posNodeFront = p;
        //�ҵ�ɾ������λ��
        while (posNode->data != *e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("�Ҳ���������\n");
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
        printf("����δ���������ȴ�������\n");
    }
    else if (L->next == NULL)
    {
        printf("��ǰ����Ϊ��\n");
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

//�ݹ�
Status ReverseList(DuLinkedList* L) {
    DuLNode* newHead;		//����ÿ�η�ת��ĵ�һ���ڵ� 
    DuLNode* p1;			//ÿ�ζ�ָ��ǰһ���ڵ�	
    DuLNode* p2;			// ����δ��תǰ����һ���ڵ� 
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

/*�ǵݹ�
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