#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 定义栈的指针与大小
typedef struct {
    char *base;     
    char *top;      
    size_t size;    
} stack_t;

// 初始化栈
void stack_init(stack_t *stack, size_t sz) {
    stack->base = malloc(sz); // 分配内存大小为sz字节，并检查是否分配成功
    if (stack->base == NULL) { 
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = stack->base; // 归零
    stack->size = sz; // 设置栈的总大小
}

// 判断栈是否为空
bool stack_is_empty(stack_t *stack) {
    return stack->top == stack->base; // 条件为栈顶指针等于栈底指针时栈 
}

// 判断栈是否已满
bool stack_is_full(stack_t *stack) {
    return (stack->base + stack->size) == stack->top; //条件为栈顶指针等于栈底指针加上栈的总大小 
}

// 将值压入栈中
bool stack_push(stack_t *stack, const void *value, size_t sz) {
    if (stack->top - stack->base + sz > stack->size) // 检查栈是否有足够空间
        return false; //  

    memcpy(stack->top, value, sz); // 将值复制到栈顶位置
    stack->top += sz; // 调整栈顶指针
    return true;
}

// 从栈中弹出值
bool stack_pop(stack_t *stack, void *value, size_t sz) {
    if (stack->top - sz < stack->base) // 检查栈中是否有足够的元素可以弹出
        return false;  

    stack->top -= sz; // 调整栈顶指针
    memcpy(value, stack->top, sz); // 从栈顶位置复制值到提供的内存区域
    return true;
}

// 获取栈顶元素，但不弹出
bool stack_top(stack_t *stack, void *value, size_t sz) {
    if (stack->top - sz < stack->base) // 检查栈中是否有足够的元素
        return false;

    memcpy(value, stack->top - sz, sz); // 从栈顶位置复制值到提供的内存区域
    return true;
}

// 删除栈，释放分配的内存
void stack_delete(stack_t *stack) {
    free(stack->base);  
}

int main(int argc, char const *argv[]) {

    stack_t stack;
    stack_init(&stack, 10); // 声明并初始化栈，大小为10字节

    float a = 10.f;
    double d = 30.0;
    int b = 20; // 声明变量

    // 将变量压入栈，分别为float、double、int类型的变量
    if (!stack_push(&stack, &a, sizeof(float))) {
        fprintf(stderr, "Failed to push float onto stack\n");
    }
    if (!stack_push(&stack, &d, sizeof(double))) {
        fprintf(stderr, "Failed to push double onto stack\n");
    }
    if (!stack_push(&stack, &b, sizeof(int))) {
        fprintf(stderr, "Failed to push int onto stack\n");
    }

    float a_r;
    double d_r;
    int b_r; // 声明变量，用于接受从栈中弹出来的变量

    // 从栈中弹出变量
    if (!stack_pop(&stack, &b_r, sizeof(int))) {
        fprintf(stderr, "Failed to pop int from stack\n");
    }
    if (!stack_pop(&stack, &d_r, sizeof(double))) {
        fprintf(stderr, "Failed to pop double from stack\n");
    }
    if (!stack_top(&stack, &a_r, sizeof(float))) {
        fprintf(stderr, "Failed to get top float from stack\n");
    }

    printf("a_r: %f, b_r: %d, d_r: %lf\n", a_r, b_r, d_r); // 打印获取的变量

    // 从栈中弹出变量
    if (!stack_pop(&stack, &a_r, sizeof(float))) {
        fprintf(stderr, "Failed to pop float from stack\n");
    }

    printf("a_r: %f, b_r: %d, d_r: %lf\n", a_r, b_r, d_r); // 打印变量

    stack_delete(&stack); // 删除栈，释放内存
    return 0;
}
