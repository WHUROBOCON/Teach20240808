#pragma once
#include"stdbool.h"

#define QUEUE_MAX 20   //定义常量，确定队列大小

//定义结构体，在结构体中定义数组以及队列读入与读出的地址代号，队列元素将储存在数组中
typedef struct queue
{
   float data[QUEUE_MAX] ;
   unsigned int r;
   unsigned int w;
}queue;

void Initqueue(queue *queue);           //初始化
bool Enqueue(queue *queue, float value);//将值存入队列
bool Dequeue(queue *queue, float *value);//将元素从队列中取出并移除
bool Queue_Front(queue *queue, float *value);//返回队列头部的元素，但不移除它
bool Queue_Is_Empty(queue *queue);           //判断队列是否为空
bool Queue_Is_Full(queue *queue);            //判断队列是否满

