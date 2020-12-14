#ifndef _STACK_H_
#define _STACK_H_


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int ElemType;
typedef int Status; 

typedef struct
{
    ElemType data[MAXSIZE];
    int top = -1;   //初始化空栈 top = -1
}SqStack;

typedef struct 
{
    ElemType data[MAXSIZE];
    int top1 = -1;
    int top2 = MAXSIZE;
}SqDoubleStack;

typedef struct StackNode
{
    ElemType data;
    StackNode *next;
} LinkStackPtr; //栈节点内容
typedef struct LinkStack
{
    LinkStackPtr *top;
    int count = 0;
} LinkStack;


//operations
Status Push(SqStack &s, ElemType e);
Status Pop(SqStack &s, ElemType &e);
Status Push(SqDoubleStack &s, ElemType e, int StackNum);
Status Pop(SqDoubleStack &s, ElemType &e, int StackNum);
Status Push(LinkStack *s, ElemType e);
Status Pop(LinkStack *s, ElemType &e);
#endif