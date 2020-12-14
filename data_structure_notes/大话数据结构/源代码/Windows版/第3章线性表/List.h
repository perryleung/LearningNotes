#ifndef _LIST_H_
#define _LIST_H_

#define MAXSIZE 20
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

typedef struct Node
{
    ElemType data;
    Node *next;
}Node;
typedef Node LinkList;

typedef struct DulNode
{
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
}DulNode;
typedef DulNode DuLinkList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

//SqList Operations
Status InitList(SqList &l);
Status ListEmpty(const SqList &l);
Status ClearList(SqList &l);
Status GetElem(const SqList &l, int i, ElemType &e);
int LocateElem(const SqList &l, ElemType e);
Status ListInsert(SqList &l, int i, ElemType e);
Status ListDelete(SqList &l, int i, ElemType &e); //删除位置i，用e返回
int ListLength(const SqList &l);

//LinkList Operations
Status GetElem(LinkList *l,int i, ElemType &e);
Status ListInsert(LinkList *l, int i, ElemType e);
Status ListDelete(LinkList *l, int i, ElemType &e);
LinkList* CreateListHead(int n);
LinkList *CreateListTail(int n);
Status ClearList(LinkList *l);


#endif