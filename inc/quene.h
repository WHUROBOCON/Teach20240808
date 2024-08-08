#pragma once
#include<stdbool.h>
#include<stdlib.h> 
#include<stdio.h>
typedef unsigned int quene_size_t; // 队列大小类型

typedef struct Quene_t
{
    char *front;//队头指针
    char *rear;//队尾指针
    quene_size_t size;
} quene_t; // 队列结构

void quene_init(quene_t *quene, quene_size_t size);             // 初始化队列
bool quene_push(quene_t *quene, void *value ,quene_size_t size); // 入队
bool quene_pop(quene_t *quene, void *value, quene_size_t size);  // 出队
bool quene_clear(quene_t *quene);                               // 清空队列
bool quene_is_empty(quene_t *quene);                            // 判断队列是否为空
bool quene_is_full(quene_t *quene);                             // 判断队列是否满
void quene_destroy(quene_t *quene);                             // 销毁队列
