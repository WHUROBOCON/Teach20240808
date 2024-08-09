#pragma once//只在第一次包含时编译此文件
#include <stdbool.h>/* 引入bool所属头文件 */
#include <stdlib.h>/* 引入malloc，free所属头文件 */
#include<string.h>/* 引入strcpy所属头文件 */
#include<stdio.h>/* 调用标准输入输出函数所属头文件 */

typedef unsigned int stack_t_size;//简化代码，定义栈的大小为无符号整型用stack_t_size表示
typedef struct Stack_t{/* 栈的结构体 */
    char *top;//栈顶指针
    char *base;//栈底指针
    stack_t_size size;//栈的大小
    
}stack_t;       

//函数声明
void stack_init();  //初始化栈  
bool stack_IS_EMPTY();  //判断栈是否为空  
bool stack_IS_FULL();   //判断栈是否已满  
bool stack_PUSH();    //进栈  
bool stack_POP();     //出栈  