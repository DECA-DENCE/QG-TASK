#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>	
#include <Windows.h>
#include "LinkStack.h"

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

int main(void)
{
    int choice;
    int* len = NULL;
    ElemType data;
    LinkStack s;
    ElemType temp;//用于获取栈顶元素及储存出栈的元素

    if (!initLStack(&s))
    {
        printf("栈初始化失败\n");
    }

    do
    {
        menu();
        choice = judge_int();
        system("cls");
        switch (choice)
        {
        case 1://判断栈是否为空
        {
            if (isEmptyLStack(&s))
            {
                printf("栈为空\n");
            }
            else
            {
                printf("栈非空\n");
            }
            break;
        }
        case 2://得到栈顶元素
        {
            if (!getTopLStack(&s, &temp))
            {
                printf("获取失败\n");
            }
            break;
        }
        case 3://清空栈
        {
            if (clearLStack(&s))
            {
                printf("清空完成\n");
            }
            else
            {
                printf("清空失败\n");
            }
            break;
        }
        case 4://销毁栈
        {
            if (destroyLStack(&s))
            {
                printf("销毁完成\n");
            }
            else
            {
                printf("销毁失败\n");
            }
            break;
        }
        case 5://检测栈的长度
        {
            if (!LStackLength(&s, len))
            {
                printf("栈为空\n");
            }
            break;
        }
        case 6://入栈
        {
            printf("请输入数据（可入多个。输入1145114后停止）：");
            while (scanf("%d", &data) && data != 1145114)
            {
                pushLStack(&s, data);
            }
            if (!pushLStack(&s, data))
            {
             printf("入栈失败\n");
            }
            break;
        }
        case 7://出栈
        {
            if (popLStack(&s, &temp))
            {
                printf("出栈完成\n");
            }
            else
            {
                printf("出栈失败\n");
            }
            break;
        }
        case 8://退出程序
        {
            break;
        }
        default:
        {
            printf("请重新输入数字！(1-8)\n");
            break;
        }
        }
    } while (choice != 8);

    system("pause");
    return 0;
}
