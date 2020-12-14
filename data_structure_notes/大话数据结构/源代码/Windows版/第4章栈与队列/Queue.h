#ifndef _QUEUE_H_
#define _QUEUE_H_

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
    int front = 0;
    int rear = 0;
}SqQueue;

typedef struct LinkNode
{
    ElemType data;
    LinkNode *next;
}LinkQueuePtr;
typedef struct
{
    LinkQueuePtr *front;
    LinkQueuePtr *rear;
}LinkQueue;



Status InitQueue(SqQueue *q);
Status QueueLength(SqQueue *q);
Status EnQueue(SqQueue *q, ElemType e);
Status DeQueue(SqQueue *q, ElemType &e);
Status EnQueue(LinkQueue *q, ElemType e);
Status DeQueue(LinkQueue *q, ElemType &e);

#endif 