#include "List.h"

Status GetElem(const SqList &l, int i, ElemType &e)
{
    if (i < 1 || i > l.length || l.length == 0)
        return ERROR;
    e = l.data[i - 1];
    return OK;
}

Status ListInsert(SqList &l, int i, ElemType e)
{
    if(l.length == MAXSIZE)
        return ERROR;
    if (i < 1 || i > l.length + 1)
        return ERROR;
    else
    {
        for (int k = l.length - 1; k >= i - 1; k--)
        {
            l.data[k++] = l.data[k];
        }
        l.data[i - 1] = e;
        l.length++;
    }
    return OK;
}

Status ListDelete(SqList &l, int i, ElemType &e)
{
    if (l.length == 0)
        return ERROR;
    if (i < 1 || i > l.length)
        return ERROR;
    e = l.data[i - 1];
    if (i <= l.length)
    {
        for (int k = i - 1; k < l.length - 1; k++)
            l.data[k] = l.data[k + 1];
    }
    l.length--;
    return OK;
}

Status GetElem(LinkList *l,int i, ElemType &e)
{
    LinkList *p = l->next;//p为第一个节点
    int j = 1;
    while(p && j < i)
    {
        p = p->next;
        j++;
    }
    //此时循环结束，j == i 或 p == NULL
    if (j > i || !p)//j>i是没有找到或出错，!p是链表太短
        return ERROR;
    e = p->data;
    return OK;
}

Status ListInsert(LinkList *l, int i, ElemType e)
{
    int j = 1;
    LinkList *p = l;    //要找到第 i-1 个节点
    while (j < i && p)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    //LinkList s; 要动态生成一个节点，这样是错误的
    //s = (LinkList)malloc(sizeof(Node)); #include<stdlib.h>
    LinkList *s = new LinkList;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList *l, int i, ElemType &e)
{
    LinkList *p = l;//第一个节点的前一个节点
    int j = 1;
    while (j < i && p)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    LinkList *q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;
    q->next = nullptr;
    return OK;
}

LinkList* CreateListHead(int n) //头插法
{
    if (n < 0)
        return nullptr;
    LinkList *head = new LinkList;
    head->data = 0;
    head->next = nullptr;
    for (int i = 0; i < n; i++)
    {
        LinkList* p = new LinkList;
        p->data = 0;
        p->next = head->next;   //刚创建的节点next指向原第一个节点，也就是head->next
        head->next = p;         //头插法，头节点next指向刚创建的节点，这就能从头开始创建
    }
    return head;
}

LinkList *CreateListTail(int n) //尾插法
{
    if (n < 0)
        return nullptr;
    LinkList *head = new LinkList;
    head->data = 0;
    head->next = nullptr;
    LinkList *tail = head;
    for (int i = 0; i < n; i++)
    {
        LinkList *p = new LinkList;
        p->data = i + 1;
        p->next = nullptr;
        tail->next = p;     //把tail指针指向 p，连接起来
        tail = p;           //更新tail 指针
    }
    return head;
}

Status ClearList(LinkList *l)
{
    if(!l)
        return ERROR;
    LinkList *p, *q;
    p = l->next;    // 第一个节点
    while(p)
    {
        q = p->next;        
        delete p;
        p->next = nullptr;
        p = q;
    }
    l->next = nullptr;
    return OK;
}

