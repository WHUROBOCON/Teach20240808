#pragma once
#include<stdbool.h>
#include<stdlib.h> 
#include<stdio.h>
typedef unsigned int queue_size_t; // 队列大小类型

typedef struct Queue_t
{
    char *front;//队头指针
    char *rear;//队尾指针
    queue_size_t size;
} Queue_t; // 队列结构

void queue_init(Queue_t *queue, queue_size_t size);             // 初始化队列
bool queue_push(Queue_t *queue, void *value ,queue_size_t size); // 入队
bool queue_pop(Queue_t *queue, void *value, queue_size_t size);  // 出队
bool queue_clear(Queue_t *queue);                               // 清空队列
bool queue_is_empty(Queue_t *queue);                            // 判断队列是否为空
bool queue_is_full(Queue_t *queue);                             // 判断队列是否满
void queue_destroy(Queue_t *queue);                             // 销毁队列
bool queue_get_front(Queue_t *queue, void *value, queue_size_t size); // 获取队头元素