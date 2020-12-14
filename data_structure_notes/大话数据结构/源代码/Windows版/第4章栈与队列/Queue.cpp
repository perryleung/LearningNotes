#include "Queue.h"
#include <cstdlib>
#include <math.h>
Status InitQueue(SqQueue *q)
{
    q->data[0] = 0;
    q->front = 0;
    q->rear = 0;
    return OK;
}

Status QueueLength(SqQueue *q)
{
    return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue *q, ElemType e)
{
    if((q->rear + 1) % MAXSIZE == q->front) //判断循环队列满的条件
        return ERROR;
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;  //尾指针前进一个单位
    return OK;
}

Status DeQueue(SqQueue *q, ElemType &e)
{
    if(q->front == q->rear) //判断循环队列空的条件
        return ERROR;
    e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return OK;
}

Status EnQueue(LinkQueue *q, ElemType e)
{
    LinkQueuePtr *p = new LinkQueuePtr;
    if(!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = nullptr;
    q->rear->next = p;  //先连上队伍
    q->rear = p;        //再更新指针
    return OK;
}

Status DeQueue(LinkQueue *q, ElemType &e)
{
    if(q->front == q->rear)
        return ERROR;
    LinkQueuePtr *p = q->front->next;   //为啥不是q->front？因为第一个节点不存东西
    e = p->data;
    q->front->next = p->next;
    if(q->rear == p)
        q->rear = q->front;
    delete p;
    p->next = nullptr;
    return OK;
}