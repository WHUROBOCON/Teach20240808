#pragma once
#include"stdbool.h"

typedef unsigned int stack_size;  //给int 类型定义一个新名字

//定义结构体，在结构体中保存栈顶元素与栈底元素的地址与栈所占的字节数size
typedef struct stack
{
    char *base;
    char *top;
    stack_size size;
}stack;

void Stack_Init(stack *stack,stack_size size);            //初始化函数
bool Stack_Is_Full(stack *stack);                         //判断栈是否满，若是，返回1，否返回0
bool Stack_Is_Empty(stack *stack);                        //判断栈是否空，若是，返回1，否返回0
bool Stack_Pop(stack *stack, void *value,stack_size sz);  //出栈函数，获取栈顶元素同时它移除
bool Stack_Push(stack *stack, void *value,stack_size sz); //入栈函数，将元素添加到栈顶
bool Stack_Top(stack *stack,void *value,stack_size sz);   //获取栈顶元素，但不移除它
void Stack_Delete(stack *stack);                          //释放空间
