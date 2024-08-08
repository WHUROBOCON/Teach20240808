#pragma once

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef unsigned int stack_size_t;

typedef struct stack {
    char*base;
    char*top;
    stack_size_t size;
} stack_t;

void stack_init(stack_t *stack,stack_size_t size);
bool stack_empty(stack_t *stack);
bool stack_full(stack_t *stack);
bool stack_push(stack_t *stack, void *value,stack_size_t size);
bool stack_pop(stack_t *stack, void *value,stack_size_t size);
bool stack_top(stack_t *stack, void *value,stack_size_t size);
void stack_delete(stack_t *stack);