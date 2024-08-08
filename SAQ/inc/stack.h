#pragma once
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack_t{ //定义栈
    char *base;
    char *top;
    unsigned int size;
} stack_t;

void stack_init(stack_t *stack,int size); //清空栈
bool stack_is_empty(stack_t *stack); //判断栈是否空，返回bool
bool stack_is_full(stack_t *stack); //判断栈是否满，返回bool
bool stack_push(stack_t *stack, void *value, int size); //给栈加元素，栈满返回False
bool stack_pop(stack_t *stack, void *value, int size); //取出栈元素，栈空返回False
void stack_destroy(stack_t *stack); //删除栈，释放内存