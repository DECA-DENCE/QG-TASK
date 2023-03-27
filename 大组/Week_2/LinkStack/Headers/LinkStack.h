#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>	
#include <stdlib.h> 
#include <malloc.h>	

typedef enum Status
{
    error,
    success
} Status;

typedef int ElemType;

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

//函数的声明
//链栈
Status initLStack(LinkStack* s);//初始化栈
Status isEmptyLStack(LinkStack* s);//判断栈是否为空
Status getTopLStack(LinkStack* s, ElemType* e);//得到栈顶元素
Status clearLStack(LinkStack* s);//清空栈
Status destroyLStack(LinkStack* s);//销毁栈
Status LStackLength(LinkStack* s, int* length);//检测栈长度
Status pushLStack(LinkStack* s, ElemType data);//入栈
Status popLStack(LinkStack* s, ElemType* data);//出栈
void menu(void);//显示界面
int judge_int(void);//使用户输入整数

Status initLStack(LinkStack* s)
{
    s->top = NULL;
    s->count = 0;
    return success;
}

Status isEmptyLStack(LinkStack* s)
{
    if (s->top == NULL)
    {
        return success;
    }
    else
    {
        return error;
    }
}

Status getTopLStack(LinkStack* s, ElemType* e)
{
    if (s->top == NULL)
    {
        printf("栈为空\n");
        return error;
    }
    else
    {
        *e = s->top->data;
        printf("栈顶元素为：%d\n", *e);
        return success;
    }
}

Status clearLStack(LinkStack* s)
{
    if (s->top == NULL)
    {
        printf("栈为空\n");
        return error;
    }
    else
    {
        s->top = NULL;
        return success;
    }
}

Status destroyLStack(LinkStack* s)
{
    while (!isEmptyLStack(s))
    {
        LinkStackPtr temp;
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    return success;
}

Status LStackLength(LinkStack* s, int* length)
{
    if (s->top == NULL)
    {
        return error;
    }
    else
    {
        length = &s->count;
        printf("当前栈的长度为%d\n", *length);
        return success;
    }
}

Status pushLStack(LinkStack* s, ElemType data)
{
    LinkStackPtr new = (LinkStackPtr)malloc(sizeof(StackNode));
    if (new == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    new->data = data;
    new->next = s->top;
    s->top = new;
    s->count++;
    return success;
}

Status popLStack(LinkStack* s, ElemType* data)
{
    if (s->top == NULL)
    {
        printf("栈为空\n");
        return error;
    }
    else
    {
        LinkStackPtr temp;
        *data = s->top->data;
        temp = s->top;
        s->top = s->top->next;
        free(temp);
        s->count--;
        return success;
    }
}

void menu(void)
{
    printf("\n\n\n\n        链栈\n");
    printf("     (栈已初始化)\n\n");
    printf("     1.判断栈是否为空\n");
    printf("     2.得到栈顶元素\n");
    printf("     3.清空栈\n");
    printf("     4.销毁栈\n");
    printf("     5.检测栈的长度\n");
    printf("     6.入栈\n");
    printf("     7.出栈\n");
    printf("     8.退出\n\n");
    printf("请输入对应的数字(1-8)：");
}

int judge_int(void)  //防止用户乱输入其他的字符
{
    int len, num = 0, arg = 1;
    char word[10];
    int m, j = 1, k;
    while (j)
    {
        scanf("%s", word);
        len = strlen(word);
        for (m = 0; m < len; m++)
        {
            if (word[m] < '0' || word[m]>'9')  //检验是否有乱输入其他字符
            {
                printf("请输入整数：");
                break;
            }
            else
            {
                if (m == len - 1)
                    j = 0;
            }
        }
    }
    j = len - 1;
    for (m = 0; m < len; m++)  // 将字符重新转换为数字
    {
        for (k = 0; k < j; k++)
            arg *= 10;
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    return num;
}
#endif