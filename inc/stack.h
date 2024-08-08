#pragma once
#include<stdbool.h>
#include<stdlib.h> 
#include<stdio.h>
typedef unsigned int stack_size_t; // 栈大小类型

typedef struct Stack_t
{
    char *base;
    char *top;
    stack_size_t size;
} stack_t; // 栈结构

void stack_init(stack_t *stack, stack_size_t size);             // 初始化栈
bool stack_push(stack_t *stack, void *data, stack_size_t size); // 入栈
bool stack_pop(stack_t *stack, void *data, stack_size_t size);  // 出栈
bool stack_clear(stack_t *stack);                               // 清空栈
bool stack_is_empty(stack_t *stack);                            // 判断栈是否为空
bool stack_is_full(stack_t *stack);                             // 判断栈是否满
void stack_destroy(stack_t *stack);                             // 销毁栈
bool stack_get_top(stack_t *stack, void *data, stack_size_t size); // 获取栈顶元素