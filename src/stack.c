#include "../inc/stack.h"

void stack_init(stack_t *stack, stack_size_t size)
{
    stack->base = malloc(size) + size; // malloc返回的是指向堆内存的指针，所以要加上size才能指向栈底
    stack->top = stack->base;
    stack->size = size; // 栈大小,stack->size是栈的大小，stack->top-stack->base是栈的元素个数
}

bool stack_push(stack_t *stack, void *data, stack_size_t size)
{
    if (stack_is_full(stack))
    {
        // 栈满时，扩容
        stack->top = realloc(stack->top, stack->size); // realloc函数的功能是重新分配size大小的内存空间,并返回指向该内存空间的指针,
        stack->top += stack->size;
    }
    stack->top -= size;                          // top指向栈顶元素的下一个位置
    stack->top = memcpy(stack->top, data, size); // memcpy函数的功能是将data中的size个字节拷贝到stack->top中

    return true;
}

bool stack_pop(stack_t *stack, void *data, stack_size_t size)
{
    if (stack->top + size > stack->base)
    {
        return false;
    }
    memcpy(data, stack->top, size); // 将栈顶元素拷贝到data中
    stack->top += size;             // top指向栈顶元素的下一个位置
    return true;
}

bool stack_clear(stack_t *stack)
{
    free(stack->base - stack->size); // 释放栈的内存空间
}

bool stack_is_empty(stack_t *stack)
{
    return stack->top == stack->base; // top指向栈顶元素的下一个位置，所以栈空时top指向栈底
}

bool stack_is_full(stack_t *stack)
{
    return (stack->base == (char *)stack->top + stack->size); // top指向栈顶元素的下一个位置，所以栈满时top指向栈底
}

bool stack_get_top(stack_t *stack, void *data, stack_size_t size)
{
    if (stack_is_empty(stack))
    {
        return false;
    }
    memcpy(data, stack->top, size); // 将栈顶元素拷贝到data中
    return true;
}

int main(int args, char *argv[])
{
    stack_t stack;
    stack_size_t size = 20;
    stack_init(&stack, size);
    float a = 10.f;
    double d = 30.f;
    int b = 20;
    printf("%f %lf %d\n", a, d, b);
    // printf("%d\n", sizeof(double));
    stack_push(&stack, &a, sizeof(float));
    stack_push(&stack, &d, sizeof(double));
    stack_push(&stack, &b, sizeof(int));

    float a1;
    double d1;
    int b1;

    stack_get_top(&stack, &b1, sizeof(float));
    printf("%d\n", b1);

    stack_pop(&stack, &b1, sizeof(int));
    stack_pop(&stack, &d1, sizeof(double));
    stack_pop(&stack, &a1, sizeof(float));
    printf("%f %lf %d\n", a1, d1, b1);
    stack_clear(&stack); // 清空栈
    return 0;
}