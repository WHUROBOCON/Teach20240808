#pragma once
#include <stdio.h>
#include <stdbool.h>
#define QUEUE_MAX_SIZE 20
typedef struct queue_t
{
    float data[QUEUE_MAX_SIZE];
    unsigned int r;
    unsigned int w;
    /* data */
} queue_t;

void queue_init(queue_t *queue);
bool queue_enqueue(queue_t *queue, float value);  // 将元素添加到队列尾部
bool queue_dequeue(queue_t *queue, float *value); // 移除头部元素并返回
bool queue_front(queue_t *queue, float *value);   // 返回头部元素但不移除
bool queue_is_empty(queue_t *queue);              // 检查队列是否为空
bool queue_is_full(queue_t *queue);               // 队列是否满
