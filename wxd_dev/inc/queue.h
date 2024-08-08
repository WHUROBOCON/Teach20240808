#pragma once//防止重复包含
#include<stdbool.h>//引入bool类型
#include<stdio.h>//引入printf()函数
#include<stdlib.h>//引入malloc()和free()函数

#define QUEUE_MAX_SIZE 30//队列最大容量

typedef struct Queue_t{//定义队列结构体
    double data[QUEUE_MAX_SIZE];
    int r,w;
    int size;
}queue_t;

//声名函数
void Queue_Init(queue_t *q);//初始化队列
bool Queue_Empty(queue_t *q);//判断队列是否为空
bool Queue_Full(queue_t *q);//判断队列是否已满
bool Queue_Put(queue_t *q, double data);//入队
bool Queue_Get(queue_t *q, double *data);//出队
bool Queue_Head(queue_t *q, double *data);//获取队首元素
void Queue_Delete(queue_t *q);//销毁队列


