#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int stack_size_t;

typedef struct stack_t {
  char *base;
  char *top;
  stack_size_t size;
} stack_t;

void stack_init(stack_t *stack, stack_size_t sz);
bool stack_is_empty(stack_t *stack);
bool stack_is_full(stack_t *stack);
bool stack_push(stack_t *stack, void *value, stack_size_t sz);
bool stack_pop(stack_t *stack, void *value, stack_size_t sz);
bool stack_top(stack_t *stack, void *value, stack_size_t sz);
void stack_delete(stack_t *stack);
