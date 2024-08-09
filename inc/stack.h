#pragma once
/*保证头文件只被编译一次，防止头文件被重复引用*/
#include <stdbool.h>   /*bool判断条件为真（true或1），则执行语句*/
#include <stdlib.h>
#include <string.h>

typedef unsigned int stack_size_t; /*typedf:为现有的类型起一个别名，使使用起来更加的方便，注意一点，它并没有产生新的类型.    
unsigned:关键字，表示该类型不带有正负号，只能表示零和正整数*/

typedef struct stack_t {    /*定义了一个新的结构体stack_t，并将结构体起了一个名字stack_t*/
  char *base;/*用于栈底地址*/
  char *top;/*用于栈顶地址（不断增长）*/
  stack_size_t size;/*栈的大小*/
} stack_t;

void stack_init(stack_t *stack, stack_size_t sz);/*初始化一个栈*/
bool stack_is_empty(stack_t *stack);/*判断栈是否是空的*/
bool stack_is_full(stack_t *stack);/*判断栈是否是满的*/
bool stack_push(stack_t *stack, void *value, stack_size_t sz);/*入栈*/
bool stack_pop(stack_t *stack, void *value, stack_size_t sz);/*出栈，返回值返回到value*/
bool stack_top(stack_t *stack, void *value, stack_size_t sz);/*取得栈顶元素但不删除*/
void stack_delete(stack_t *stack);/*删除栈*/