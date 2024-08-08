#include"string.h"
#include"inc/queue.h"
#include"stdlib.h"
#include"stdio.h"

//队列遵循先进先出的原则
void Initqueue(queue *queue)  //初始化
{
    queue->r=queue->w=0;
}
bool Enqueue(queue *queue, float value)
{
    if (Queue_Is_Full(queue)) return false;
    queue->data[queue->w]=value;
    queue->w=(queue->w+1)% QUEUE_MAX;//为了避免产生溢出的现象，这里采用相除取余的方法，构成循环队列
    return true;
}
bool Dequeue(queue *queue, float *value)
{
  if (Queue_Is_Empty(queue)) return false;
  *value = queue->data[queue->r];
  queue->r= (queue->r+1)%QUEUE_MAX;
  return true;
}
bool Queue_Front(queue *queue, float *value)
{
  if (Queue_Is_Empty(queue)) return false;
  *value = queue->data[queue->r];
  return true;
}
bool Queue_Is_Empty(queue *queue)
{
    return (queue->w-queue->r==0) ;             //当读入读出位置代号相同时，代表队列为空
}
bool Queue_Is_Full(queue *queue)
{
    return ((queue->w+1)%QUEUE_MAX==queue->r) ;  //为了能够判断队列是否为满，这里舍弃了一个储存空间，即一次最多只能存入QUEUE_MAX-1个数据
}
void main()
{  
    queue queue;
    float a[5]={1.0,2.3,3,4.78,5.552};   //定义数组，数组元素后续将被存入队列中
    Initqueue(&queue);
    for (int i = 0; i < 5; i++)          //循环，利用Enqueue函数将数组元素存入队列内
    { 
      Enqueue(&queue, a[i]);
    }
   for (int j = 0; j< 5; j++)            ////循环，利用函数Dequeue导出队列元素
    { float n=0;
      Dequeue(&queue, &n);
      printf("%lf\n",n);
    }
}
