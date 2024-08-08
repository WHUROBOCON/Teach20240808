#pragma once

#include<stdbool.h>
#include<stdio.h>

#define QUEUE_MAX_SIZE 10

typedef struct queue_t{
    // float data[QUEUE_MAX_SIZE];
    float data[QUEUE_MAX_SIZE+1];
    unsigned int r;
    unsigned int w;
}queue_t;

void queue_init(queue_t *queue);
bool queue_enqueue(queue_t *queue,float value);
bool queue_dequeue(queue_t *queue,float *value);
bool queue_front(queue_t *queue,float *value);
bool queue_is_empty(queue_t *queue);
bool queue_is_full(queue_t *queue);