#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include"calculator.h"

int main(void)
{
    //共用变量
    int i = 0;//数组下标
    //中缀表达式转换后缀表达式的变量
    LinkStack s;
    char c, d;//处理输入的数据
    char data[DATASIZE];//存放后缀表达式
    //计算后缀表达式的变量
    linkstack s1;
    char str[MAXBUFFER];//缓冲区，用于处理连续的数字
    elemtype n1, n2;//处理输出的数据
    int n = 0;//缓冲区内计数器

    //初始化两个栈
    if (!initLStack(&s))
    {
        printf("初始化失败\n");
        system("pause");
        return -1;
    }
    if (!initlstack(&s1))
    {
        printf("初始化失败\n");
        system("pause");
        return -1;
    }

    //下面将中缀表达式转换为后缀表达式储存在数组data中
    printf("请输入中缀表达式，以=作为结束标志(只能进行整数运算)：");
    scanf("%c", &c);
    while (c != '=')//一直接收用户输入，直到读取到=为止
    {
        while (c >= '0' && c <= '9')//整数直接存入数组
        {
            data[i] = c;
            i++;
            scanf("%c", &c);
            if (c < '0' || c>'9')//处理连续的数字
            {
                data[i] = ' ';
                i++;
            }
        }

        if (c == ')')
        {
            Pop(&s, &d);//出栈
            while (d != '(')//不是左括号就存入数组
            {
                data[i] = d;
                i++;
                Pop(&s, &d);
            }
        }
        else if (c == '+' || c == '-')
        {
            if (!notEmptyLStack(&s))//栈空即入栈
            {
                Push(&s, c);
            }
            else//栈非空则比较栈顶元素
            {
                do
                {
                    Pop(&s, &d);
                    if (d == '(')
                    {
                        Push(&s, d);
                    }
                    else//不是左括号就存入数组
                    {
                        data[i] = d;
                        i++;
                    }
                } while (notEmptyLStack(&s) && d != '(');
                //直到栈空或者读取到左括号
                Push(&s, c);//然后再入栈
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
            printf("\n出错：输入格式错误！\n");
            printf("请切换成英文，匹配好括号或者不要输入空格等等\n");
            system("pause");
            return -1;
        }

        scanf("%c", &c);
    }

    //检查如果=前无运算符,eg:1=
    if (!notEmptyLStack(&s))
    {
        printf("\n出错：输入格式错误！\n");
        printf("请切换成英文，匹配好括号或者不要输入空格等等\n");
        system("pause");
        return -1;
    }

    while (notEmptyLStack(&s))//将栈内剩余对象存放到数组
    {

        Pop(&s, &data[i]);
        i++;
        data[i] = '=';
        data[i + 1] = '\0';//字符串结束标志
    }

    printf("\n后缀表达式：\n");
    printf("%s\n", data);

    //下面计算后缀表达式
    for (i = 0; data[i] != '\0'; i++)
    {
        //下面对数字进行处理
        while (isdigit(data[i]))
        {
            str[n++] = data[i++];
            str[n] = '\0';//字符串结束
            if (n >= MAXBUFFER)
            {
                printf("输入的单个数据过大\n");
                system("pause");
                return -1;
            }
            if (data[i] == ' ')//读取到空格时对前面的所有数字进行处理
            {
                n1 = atoi(str);//将字符串转换成整型数据
                push(&s1, n1);
                n = 0;//计数器重新初始化
                break;
            }
        }
        switch (data[i])//过滤掉数字后对剩下的符号进行选择
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
                printf("\n出错：除数不能为零\n");
                system("pause");
                return -1;
            }
            break;
        }
        }
    }
    pop(&s1, &n1);
    printf("\n计算结果为：%d\n\n", n1);

    system("pause");

    return 0;
}