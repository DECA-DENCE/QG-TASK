#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>	
#include <Windows.h>
#include "LinkStack.h"

//����������
//��ջ
Status initLStack(LinkStack* s);//��ʼ��ջ
Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack* s, ElemType* e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack* s);//���ջ
Status destroyLStack(LinkStack* s);//����ջ
Status LStackLength(LinkStack* s, int* length);//���ջ����
Status pushLStack(LinkStack* s, ElemType data);//��ջ
Status popLStack(LinkStack* s, ElemType* data);//��ջ
void menu(void);//��ʾ����
int judge_int(void);//ʹ�û���������

int main(void)
{
    int choice;
    int* len = NULL;
    ElemType data;
    LinkStack s;
    ElemType temp;//���ڻ�ȡջ��Ԫ�ؼ������ջ��Ԫ��

    if (!initLStack(&s))
    {
        printf("ջ��ʼ��ʧ��\n");
    }

    do
    {
        menu();
        choice = judge_int();
        system("cls");
        switch (choice)
        {
        case 1://�ж�ջ�Ƿ�Ϊ��
        {
            if (isEmptyLStack(&s))
            {
                printf("ջΪ��\n");
            }
            else
            {
                printf("ջ�ǿ�\n");
            }
            break;
        }
        case 2://�õ�ջ��Ԫ��
        {
            if (!getTopLStack(&s, &temp))
            {
                printf("��ȡʧ��\n");
            }
            break;
        }
        case 3://���ջ
        {
            if (clearLStack(&s))
            {
                printf("������\n");
            }
            else
            {
                printf("���ʧ��\n");
            }
            break;
        }
        case 4://����ջ
        {
            if (destroyLStack(&s))
            {
                printf("�������\n");
            }
            else
            {
                printf("����ʧ��\n");
            }
            break;
        }
        case 5://���ջ�ĳ���
        {
            if (!LStackLength(&s, len))
            {
                printf("ջΪ��\n");
            }
            break;
        }
        case 6://��ջ
        {
            printf("���������ݣ�������������1145114��ֹͣ����");
            while (scanf("%d", &data) && data != 1145114)
            {
                pushLStack(&s, data);
            }
            if (!pushLStack(&s, data))
            {
             printf("��ջʧ��\n");
            }
            break;
        }
        case 7://��ջ
        {
            if (popLStack(&s, &temp))
            {
                printf("��ջ���\n");
            }
            else
            {
                printf("��ջʧ��\n");
            }
            break;
        }
        case 8://�˳�����
        {
            break;
        }
        default:
        {
            printf("�������������֣�(1-8)\n");
            break;
        }
        }
    } while (choice != 8);

    system("pause");
    return 0;
}
