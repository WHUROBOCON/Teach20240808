#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef unsigned int stack_size_t;

typedef struct stack_t
{
    char *base;
    char *top;
    stack_size_t size;
    /* data */
} stack_t;

void stack_init(stack_t *stack, stack_size_t sz);
bool stack_is_empty(stack_t *stack);
bool stack_is_full(stack_t *stack);
bool stack_push(stack_t *stack, stack_size_t sz, void *value);
bool stack_pop(stack_t *stack, stack_size_t sz, void *value);
bool stack_top(stack_t *stack, stack_size_t sz, void *value);
void stack_delete(stack_t *stack);