#pragma once
#ifndef _calculator_h_
#define _calculator_h_
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

#define DATASIZE 50//存放后缀表达式的数组长度
#define MAXBUFFER 10//最大缓冲区大小 

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

//函数的声明(链栈)
//栈内元素为字符型，用于处理输入的数据 
Status initLStack(LinkStack* s);//初始化栈
Status notEmptyLStack(LinkStack* s);//判断栈是否为空
void Push(LinkStack* s, ElemType data);//入栈
void Pop(LinkStack* s, ElemType* data);//出栈
//栈内元素为整型，用于处理输出的数据 
Status initlstack(linkstack* s);//初始化栈
void push(linkstack* s, elemtype data);//入栈
void pop(linkstack* s, elemtype* data);//出栈

//下面是字符型链栈基本操作的函数 
Status initLStack(LinkStack* s)
{
    s->top = NULL;
    s->count = 0;
    return success;
}

Status notEmptyLStack(LinkStack* s)
{
    if (s->top != NULL)//非空返回1
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
        printf("内存分配失败\n");
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
        printf("栈空\n");
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

//下面是整型链栈基本操作的函数
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
        printf("内存分配失败\n");
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
    if (s->top == NULL)//栈空，对应错误：如用户输入：1+= 
    {
        printf("\n出错：输入格式错误！\n");
        printf("请切换成英文，匹配好括号或者不要输入空格等等\n");
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