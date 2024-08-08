#pragma once

#define QUEUE_MAX_SIZE 20

#include<stdlib.h>
#include<stdbool.h>
typedef struct queue_t{ //定义队列
    float data[QUEUE_MAX_SIZE];
    unsigned int r;
    unsigned int w;
}queue_t;
void queue_inti(queue_t *queue); //初始化对列
bool queue_enqueue(queue_t *queue,float value); //写入元素
bool queue_dequeue(queue_t *queue,float *value); //读出元素
bool queue_front(queue_t *queue,float *value); //输出头部元素
bool queue_is_empty(queue_t *queue); // 判断是否空
bool queue_is_full(queue_t *queue); // 判断是否满