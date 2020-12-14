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
    if((q->rear + 1) % MAXSIZE == q->front) //�ж�ѭ��������������
        return ERROR;
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;  //βָ��ǰ��һ����λ
    return OK;
}

Status DeQueue(SqQueue *q, ElemType &e)
{
    if(q->front == q->rear) //�ж�ѭ�����пյ�����
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
    q->rear->next = p;  //�����϶���
    q->rear = p;        //�ٸ���ָ��
    return OK;
}

Status DeQueue(LinkQueue *q, ElemType &e)
{
    if(q->front == q->rear)
        return ERROR;
    LinkQueuePtr *p = q->front->next;   //Ϊɶ����q->front����Ϊ��һ���ڵ㲻�涫��
    e = p->data;
    q->front->next = p->next;
    if(q->rear == p)
        q->rear = q->front;
    delete p;
    p->next = nullptr;
    return OK;
}