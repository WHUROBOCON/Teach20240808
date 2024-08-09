/*队列特点*/
#pragma once

#include <stdbool.h>
#include <stdio.h>

#define QUEUE_MAX_SIZE 20

typedef struct queue_t {
  float data[QUEUE_MAX_SIZE];/*定义数组存放队列*/
  unsigned int r;
  unsigned int w;
} queue_t;

void queue_init(queue_t *queue);/*初始化队列*/
bool queue_enqueue(queue_t *queue, float value);// * Enqueue: 将元素添加到队列的尾部。
bool queue_dequeue(queue_t *queue, float *value);// * Dequeue: 从队列的头部移除并返回元素。
bool queue_front(queue_t *queue, float *value);// * Front: 返回队列头部的元素，但不移除它。
bool queue_is_empty(queue_t *queue);// * IsEmpty: 检查队列是否为空。
bool queue_is_full(queue_t *queue);// * IsFull: 检查队列是否为满。
