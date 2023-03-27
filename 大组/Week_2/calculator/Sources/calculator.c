#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include"calculator.h"

int main(void)
{
    //���ñ���
    int i = 0;//�����±�
    //��׺���ʽת����׺���ʽ�ı���
    LinkStack s;
    char c, d;//�������������
    char data[DATASIZE];//��ź�׺���ʽ
    //�����׺���ʽ�ı���
    linkstack s1;
    char str[MAXBUFFER];//�����������ڴ�������������
    elemtype n1, n2;//�������������
    int n = 0;//�������ڼ�����

    //��ʼ������ջ
    if (!initLStack(&s))
    {
        printf("��ʼ��ʧ��\n");
        system("pause");
        return -1;
    }
    if (!initlstack(&s1))
    {
        printf("��ʼ��ʧ��\n");
        system("pause");
        return -1;
    }

    //���潫��׺���ʽת��Ϊ��׺���ʽ����������data��
    printf("��������׺���ʽ����=��Ϊ������־(ֻ�ܽ�����������)��");
    scanf("%c", &c);
    while (c != '=')//һֱ�����û����룬ֱ����ȡ��=Ϊֹ
    {
        while (c >= '0' && c <= '9')//����ֱ�Ӵ�������
        {
            data[i] = c;
            i++;
            scanf("%c", &c);
            if (c < '0' || c>'9')//��������������
            {
                data[i] = ' ';
                i++;
            }
        }

        if (c == ')')
        {
            Pop(&s, &d);//��ջ
            while (d != '(')//���������žʹ�������
            {
                data[i] = d;
                i++;
                Pop(&s, &d);
            }
        }
        else if (c == '+' || c == '-')
        {
            if (!notEmptyLStack(&s))//ջ�ռ���ջ
            {
                Push(&s, c);
            }
            else//ջ�ǿ���Ƚ�ջ��Ԫ��
            {
                do
                {
                    Pop(&s, &d);
                    if (d == '(')
                    {
                        Push(&s, d);
                    }
                    else//���������žʹ�������
                    {
                        data[i] = d;
                        i++;
                    }
                } while (notEmptyLStack(&s) && d != '(');
                //ֱ��ջ�ջ��߶�ȡ��������
                Push(&s, c);//Ȼ������ջ
            }
        }
        else if (c == '(' || c == '*' || c == '/')
        {
            Push(&s, c);
        }
        else if (c == '=')
        {
            break;
        }
        else
        {
            printf("\n���������ʽ����\n");
            printf("���л���Ӣ�ģ�ƥ������Ż��߲�Ҫ����ո�ȵ�\n");
            system("pause");
            return -1;
        }

        scanf("%c", &c);
    }

    //������=ǰ�������,eg:1=
    if (!notEmptyLStack(&s))
    {
        printf("\n���������ʽ����\n");
        printf("���л���Ӣ�ģ�ƥ������Ż��߲�Ҫ����ո�ȵ�\n");
        system("pause");
        return -1;
    }

    while (notEmptyLStack(&s))//��ջ��ʣ������ŵ�����
    {

        Pop(&s, &data[i]);
        i++;
        data[i] = '=';
        data[i + 1] = '\0';//�ַ���������־
    }

    printf("\n��׺���ʽ��\n");
    printf("%s\n", data);

    //��������׺���ʽ
    for (i = 0; data[i] != '\0'; i++)
    {
        //��������ֽ��д���
        while (isdigit(data[i]))
        {
            str[n++] = data[i++];
            str[n] = '\0';//�ַ�������
            if (n >= MAXBUFFER)
            {
                printf("����ĵ������ݹ���\n");
                system("pause");
                return -1;
            }
            if (data[i] == ' ')//��ȡ���ո�ʱ��ǰ����������ֽ��д���
            {
                n1 = atoi(str);//���ַ���ת������������
                push(&s1, n1);
                n = 0;//���������³�ʼ��
                break;
            }
        }
        switch (data[i])//���˵����ֺ��ʣ�µķ��Ž���ѡ��
        {
        case '+':
        {
            pop(&s1, &n1);
            pop(&s1, &n2);
            push(&s1, n1 + n2);
            break;
        }
        case '-':
        {
            pop(&s1, &n1);
            pop(&s1, &n2);
            push(&s1, n2 - n1);
            break;
        }
        case '*':
        {
            pop(&s1, &n1);
            pop(&s1, &n2);
            push(&s1, n1 * n2);
            break;
        }
        case '/':
        {
            pop(&s1, &n1);
            pop(&s1, &n2);
            if (n1 != 0)
                push(&s1, n2 / n1);
            else
            {
                printf("\n������������Ϊ��\n");
                system("pause");
                return -1;
            }
            break;
        }
        }
    }
    pop(&s1, &n1);
    printf("\n������Ϊ��%d\n\n", n1);

    system("pause");

    return 0;
}