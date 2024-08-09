#pragma once

#include <stdbool.h>
#include <stdio.h>

#define QUEUE_MAX_SIZE 20

typedef struct queue_t {
  float data[QUEUE_MAX_SIZE];
  unsigned int r;
  unsigned int w;
} queue_t;

void queue_init(queue_t *queue);
bool queue_enqueue(queue_t *queue, float value);
bool queue_dequeue(queue_t *queue, float *value);
bool queue_front(queue_t *queue, float *value);
bool queue_is_empty(queue_t *queue);
bool queue_is_full(queue_t *queue);

// * Enqueue: 将元素添加到队列的尾部。
// * Dequeue: 从队列的头部移除并返回元素。
// * Front: 返回队列头部的元素，但不移除它。
// * IsEmpty: 检查队列是否为空。
