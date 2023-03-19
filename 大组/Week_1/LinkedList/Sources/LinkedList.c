#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

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

//����������
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
void menu(void);

void menu(void)
{
    printf("\n\n\n\n������ADT\n\n");
    printf("1.����������\n");
    printf("2.��������\n");
    printf("3.������\n");
    printf("4.ɾ�����\n");
    printf("5.��������\n");
    printf("6.��������\n");
    printf("7.��ת����\n");
    printf("8.�ж������Ƿ�ɻ�\n");
    printf("9.��������ż����\n");
    printf("10.�����м���\n");
    printf("11.�˳�\n");
    printf("\n�������Ӧ������(1-11)��");
}

int main(void)
{
    int choice, num = 0;
    LinkedList head = NULL;

    do
    {
        menu();
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 1://����������
        {
            if (InitList(&head))
            {
                printf("���������ɹ�\n");
            }
            else
            {
                printf("��������ʧ��\n");
            }
            break;
        }
        case 2://��������
        {
            DestroyList(&head);
            printf("�����������\n");
            break;
        }
        case 3://��������
        {
            if (head == NULL)
            {
                printf("����Ϊ�գ� ���ȴ�������\n");
            }
            else
            {
                printf("���������ݣ�");
                scanf("%d", &num);
                if (InsertList(head, num))
                {
                    printf("���ݲ���ɹ�\n");
                }
                else
                {
                    printf("���ݲ���ʧ��\n");
                }
            }
            break;
        }
        case 4://ɾ������
        {
            printf("����ɾ���ĸ����ݣ�");
            scanf("%d", &num);
            if (DeleteList(head, num))
            {
                printf("����ɾ���ɹ�\n");
            }
            else
            {
                printf("����ɾ��ʧ��\n");
            }
            break;
        }
        case 5://��������
        {
            if (head == NULL || head->next == NULL)
            {
                printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
            }
            else
            {
                TraverseList(head);
            }
            break;
        }
        case 6://��������
        {
            printf("��������Ҫ���ҵ����ݣ�");
            scanf("%d", &num);
            if (SearchList(head, num))
            {
                printf("��������\n");
            }
            else
            {
                printf("����������\n");
            }
            break;
        }
        case 7://��ת����
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ�ջ�������ֻ�����������\n");
                printf("����תʧ��\n");
            }
            else
            {
                if (ReverseList(&head))
                {
                    printf("����ת�ɹ�\n");
                }
                else
                {
                    printf("����תʧ��\n");
                }

            }
            break;
        }
        case 8://�ж������Ƿ�ɻ�
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ��\n");
            }
            else
            {
                if (IsLoopList(head))
                {
                    printf("����ɻ�\n");
                }
                else
                {
                    printf("����û�гɻ�\n");
                }
            }
            break;
        }
        case 9://��������ż����
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ��\n");
            }
            else
            {
                if (Exchange(head))
                {
                    printf("�����ѵ���\n");
                }
                else
                {
                    printf("�����ܵ���\n");
                }
            }
            break;
        }
        case 10://�����м���
        {
            if (head == NULL || head->next == NULL)
            {
                printf("���ǿ�����\n");
            }
            else
            {
                printf("�����м䴢���ֵΪ%d\n", (FindMidNode(head))->data);
            }
            break;
        }
        case 11://��������
        {
            DestroyList(&head);
            break;
        }
        default:
        {
            printf("�������������֣�(1-11)\n");
            break;
        }
        }
    } while (choice != 11);

    return 0;
}