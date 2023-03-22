#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include"DoubleLinkedList.h"

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
void menu(void);

void menu(void)
{
    printf("\n\n\n\n˫����ADT\n\n");
    printf("1.����������\n");
    printf("2.��������\n");
    printf("3.ͷ�巨��������\n");
    printf("4.ɾ������\n");
    printf("5.��������\n");
    printf("6.�ж������Ƿ�ɻ�\n"); 
    printf("7.��ת����\n");
    printf("8.�˳�\n");
    printf("\n�������Ӧ������(1-8)��");
}

int main(void)
{
    int choice, num = 0;
    DuLinkedList head;
    head = NULL;

    do
    {
        menu();
        scanf("%d",&choice);
        system("cls");
        switch (choice)
        {
        case 1://����������
        {
            if (InitList_DuL(&head))
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
            DestroyList_DuL(&head);
            printf("�������ٳɹ�\n");
            break;
        }
        case 3://ͷ�巨��������
        {
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
                    printf("���������ݣ�");
                    scanf("%d", &newNode->data);
                    if (InsertBeforeList_DuL(head, newNode))
                    {
                        printf("���ݲ���ɹ�\n");
                    }
                    else
                    {
                        printf("���ݲ���ʧ��\n");
                    }
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
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else
            {
                printf("����ɾ���ĸ����ݣ�");
                scanf("%d", &num);
                if (DeleteList_DuL(head, &num))
                {
                    printf("����ɾ���ɹ�\n");
                }
                else
                {
                    printf("����ɾ��ʧ��\n");
                }
            }
            break;
        }
        case 5://��������
        {
            TraverseList_DuL(head);
            break;
        }
        case 6://�ж������Ƿ�ɻ�
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
        case 8://�˳����� 
        {
            DestroyList_DuL(&head);
            break;
        }
        default:
        {
            printf("��������������!(1-8)\n");
            break;
        }
        }
    } while (choice != 8);

    return 0;
}