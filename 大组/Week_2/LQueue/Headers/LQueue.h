#pragma once
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//链式队列结构
typedef struct node
{
    void* data;                   //数据域指针
    struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;
char type;
char datatype[30];

void InitLQueue(LQueue* Q); //初始化队列
void DestoryLQueue(LQueue* Q);  //销毁队列
Status IsEmptyLQueue(const LQueue* Q);  //检查队列是否为空
Status GetHeadLQueue(LQueue* Q, void* e);   //查看队头元素
int LengthLQueue(LQueue* Q);    //确定队列长度
Status EnLQueue(LQueue* Q, void* data); //入队操作
Status DeLQueue(LQueue* Q); //出队操作
void ClearLQueue(LQueue* Q);    //清空队列
Status TraverseLQueue(const LQueue* Q);   //遍历函数操作

//初始化队列
void InitLQueue(LQueue* Q)
{
    Q->front = Q->rear = (Node*)malloc(sizeof(Node));//生成新的结点作为头节点且让头尾指针指向它 
    Q->front->next = NULL;//头节点 
    Q->length = 0;
}

//销毁队列
void DestoryLQueue(LQueue* Q)
{
    while (Q->front )//非空
    {
        //出队
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

//检查队列是否为空
Status IsEmptyLQueue(const LQueue* Q)
{
    if (Q->front == NULL && Q->rear == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//查看队头元素
Status GetHeadLQueue(LQueue* Q, void *e)
{
    if (Q->front == NULL)
    {
        printf("empty!\n");
        return FALSE;
    }
    else
    {
        e = Q->front->data;
        printf("Quene:%d\n:",e);
        return TRUE;
    }
}

//确定队列长度
int LengthLQueue(LQueue* Q)
{
    if (IsEmptyLQueue(Q))
    {
        return 0;
    }
    else
    {
        int *len =& Q->length;
        printf("length:%d\n", *len);
    }
}

//入队操作
Status EnLQueue(LQueue* Q, void* data)
{
    Node* p = (Node*)malloc(sizeof(Node));
    if (!p) {  //如果p为空开辟结点失败
        return FALSE;
    }
    p->data = data;
    p->next = NULL;
    Q->rear->next = p;  //让rear指针指向的元素的next指向新插入的结点p
    Q->rear = p;  //调整rear指针位置
    Q->length++;
    return TRUE;
}

//出队操作
Status DeLQueue(LQueue* Q)
{
    if (Q->rear == Q->front) 
    {
        return FALSE;
    }
    Node* p = Q->front->next;   //用指针p来记录要删除的结点
    Q->front->next = p->next;
    if (Q->rear == p) 
    {		//如果rear指针所指向的元素为最后一个元素，调整rear指针的位置
        Q->rear = Q->front;
    }
    free(p);
    Q->length--;
    p = NULL;  //虽然free（）了p，但是p仍然会记录此时的地址
    return TRUE;
}

//清空队列
void ClearLQueue(LQueue* Q)
{
    if (Q->front == NULL)
    {
        printf("empty!\n");
    }
    else
    {
        Q->front = NULL;
    }
}

//遍历函数操作
Status TraverseLQueue(const LQueue* Q)
{
    Node* q = Q->front;
    printf("Quene：");
    while (q != NULL)
    {
        printf("%d",q->data);
        q = q->next;
    }
    printf("\n");
}

#endif