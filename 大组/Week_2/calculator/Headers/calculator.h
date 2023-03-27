#pragma once
#ifndef _calculator_h_
#define _calculator_h_
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

#define DATASIZE 50//��ź�׺���ʽ�����鳤��
#define MAXBUFFER 10//��󻺳�����С 

typedef char ElemType;
typedef int elemtype;

typedef enum Status
{
    error,
    success
} Status;

typedef struct StackNode
{
    ElemType data;
    struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int	count;
}LinkStack;

typedef struct stacknode
{
    elemtype data;
    struct stacknode* next;
}stacknode, * linkstackptr;

typedef struct linkstack
{
    linkstackptr top;
    int	count;
}linkstack;

//����������(��ջ)
//ջ��Ԫ��Ϊ�ַ��ͣ����ڴ������������ 
Status initLStack(LinkStack* s);//��ʼ��ջ
Status notEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
void Push(LinkStack* s, ElemType data);//��ջ
void Pop(LinkStack* s, ElemType* data);//��ջ
//ջ��Ԫ��Ϊ���ͣ����ڴ������������ 
Status initlstack(linkstack* s);//��ʼ��ջ
void push(linkstack* s, elemtype data);//��ջ
void pop(linkstack* s, elemtype* data);//��ջ

//�������ַ�����ջ���������ĺ��� 
Status initLStack(LinkStack* s)
{
    s->top = NULL;
    s->count = 0;
    return success;
}

Status notEmptyLStack(LinkStack* s)
{
    if (s->top != NULL)//�ǿշ���1
    {
        return success;
    }
    else
    {
        return error;
    }
}

void Push(LinkStack* s, ElemType data)
{
    LinkStackPtr new = (LinkStackPtr)malloc(sizeof(StackNode));
    if (new == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    new->data = data;
    new->next = s->top;
    s->top = new;
    s->count++;
}

void Pop(LinkStack* s, ElemType* data)
{
    if (s->top == NULL)
    {
        printf("ջ��\n");
        system("pause");
        exit(0);
    }
    else
    {
        LinkStackPtr temp;
        *data = s->top->data;
        temp = s->top;
        s->top = s->top->next;
        free(temp);
        s->count--;
    }
}

//������������ջ���������ĺ���
Status initlstack(linkstack* s)
{
    s->top = NULL;
    s->count = 0;
    return success;
}

void push(linkstack* s, elemtype data)
{
    linkstackptr new = (linkstackptr)malloc(sizeof(stacknode));
    if (new == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(0);
    }
    new->data = data;
    new->next = s->top;
    s->top = new;
    s->count++;
}

void pop(linkstack* s, elemtype* data)
{
    if (s->top == NULL)//ջ�գ���Ӧ�������û����룺1+= 
    {
        printf("\n���������ʽ����\n");
        printf("���л���Ӣ�ģ�ƥ������Ż��߲�Ҫ����ո�ȵ�\n");
        system("pause");
        exit(0);
    }
    else
    {
        linkstackptr temp;
        *data = s->top->data;
        temp = s->top;
        s->top = s->top->next;
        free(temp);
        s->count--;
    }
}
#endif