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

//函数的声明
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
    printf("\n\n\n\n双链表ADT\n\n");
    printf("1.创建空链表\n");
    printf("2.销毁链表\n");
    printf("3.头插法插入数据\n");
    printf("4.删除数据\n");
    printf("5.遍历链表\n");
    printf("6.判断链表是否成环\n"); 
    printf("7.反转链表\n");
    printf("8.退出\n");
    printf("\n请输入对应的数字(1-8)：");
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
        case 1://创建空链表
        {
            if (InitList_DuL(&head))
            {
                printf("空链表创建成功\n");
            }
            else
            {
                printf("空链表创建失败\n");
            }
            break;
        }
        case 2://销毁链表
        {
            DestroyList_DuL(&head);
            printf("链表销毁成功\n");
            break;
        }
        case 3://头插法插入数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
                    printf("请输入数据：");
                    scanf("%d", &newNode->data);
                    if (InsertBeforeList_DuL(head, newNode))
                    {
                        printf("数据插入成功\n");
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                else
                {
                    printf("数据插入失败\n");
                }
            }
            break;
        }
        case 4://删除数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                printf("你想删除哪个数据：");
                scanf("%d", &num);
                if (DeleteList_DuL(head, &num))
                {
                    printf("数据删除成功\n");
                }
                else
                {
                    printf("数据删除失败\n");
                }
            }
            break;
        }
        case 5://遍历链表
        {
            TraverseList_DuL(head);
            break;
        }
        case 6://判断链表是否成环
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空\n");
            }
            else
            {
                if (IsLoopList(head))
                {
                    printf("链表成环\n");
                }
                else
                {
                    printf("链表没有成环\n");
                }
            }
            break;
        }
        case 7://反转链表
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空或者链表只含有两个结点\n");
                printf("链表反转失败\n");
            }
            else
            {
                if (ReverseList(&head))
                {
                    printf("链表反转成功\n");
                }
                else
                {
                    printf("链表反转失败\n");
                }

            }
            break;
        }
        case 8://退出程序 
        {
            DestroyList_DuL(&head);
            break;
        }
        default:
        {
            printf("请重新输入数字!(1-8)\n");
            break;
        }
        }
    } while (choice != 8);

    return 0;
}