#include "Stack.h"

Status Push(SqStack &s, ElemType e)
{
    if(s.top == MAXSIZE - 1)
        return ERROR;
    s.top++;
    s.data[s.top] = e;
    return OK;
}

Status Pop(SqStack &s, ElemType &e)
{
    if(s.top == -1)
        return ERROR;
    e = s.data[s.top];
    s.top--;
    return OK;
}

Status Push(SqDoubleStack &s, ElemType e, int StackNum)
{
    if(s.top1 + 1 == s.top2)
        return ERROR;
    if(StackNum == 1)
    {
        s.data[++s.top1] = e;
        return OK;
    }
    if(StackNum == 2)
    {
        s.data[--s.top2] = e;
        return OK;
    }
    return ERROR;
}

Status Pop(SqDoubleStack &s, ElemType &e, int StackNum)
{
    if(StackNum == 1)
    {
        if(s.top1 == -1)
            return ERROR;
        e = s.data[s.top1--];
        return OK;
    }
    if(StackNum == 2)
    {
        if(s.top2 == MAXSIZE)
            return ERROR;
        e = s.data[s.top2++];
        return OK;
    }
    return ERROR;
}

Status Push(LinkStack *s, ElemType e)
{
    LinkStackPtr *p = new LinkStackPtr;
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->count++;
    return OK;
}

Status Pop(LinkStack *s, ElemType &e)
{
    if(s->count == 0)
        return ERROR;
    LinkStackPtr *p = s->top;
    e = p->data;
    s->top = s->top->next;
    s->count--;
    delete p;
    p = nullptr;
    return OK;
}