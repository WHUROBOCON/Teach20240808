#include "../inc/stack.h"

void stack_init(stack_t *stack, stack_size_t sz)
{
    stack->base = malloc(sz) + sz; // 指向分配的内存块的最高地址
    stack->top = stack->base;
    stack->size = sz;
} // 初始化栈

bool stack_is_empty(stack_t *stack)
{
    return stack->base == stack->top;
} // 判断栈是否为空
bool stack_is_full(stack_t *stack)
{
    return (stack->base - stack->top == stack->size);
}
// 栈是从高地址开始分配，所以栈底地址大于栈顶
bool stack_push(stack_t *stack, stack_size_t sz, void *value)
{
    if ((stack->base - (stack->top - sz) > stack->size)) // 存入数值后,top移动数值的内存位数，比较base-top和栈的size大小，如果base-top更大，则溢出，返回存入失败。
        return false;
    stack->top -= sz;              // 存入时要先移动top指针，内存地址减小
    memcpy(stack->top, value, sz); // 将value指向的值复制到top指向的位置
    return true;
}
bool stack_pop(stack_t *stack, stack_size_t sz, void *value)
{
    if (stack->top + sz > stack->base) // 判断栈道里存的位数是否满足要取的位数的要求
    {
        return false;
    }
    // 说明要取的位数大于存着的位数
    memcpy(value, stack->top, sz);
    stack->top = stack->top + sz; // 取出后，内存地址增大
    return true;
}
void stack_delete(stack_t *stack)
{
    free(stack->base - stack->size);
}

bool stack_top(stack_t *stack, stack_size_t sz, void *value)
{
    if (stack->top + sz > stack->base)
    {
        return false;
    }
    memcpy(value, stack->top, sz);
    return true;
}

int main(int argc, char const *argv[])
{
    stack_t stack;
    stack_init(&stack, 10);
    float a = 1.0;
    double d = 3.0;
    int b = 2;
    stack_push(&stack, sizeof(float), &a);  // 4
    stack_push(&stack, sizeof(double), &d); // 8
    stack_push(&stack, sizeof(int), &b);    // 4
    float a_r;
    double d_r;
    int b_r;
    stack_pop(&stack, sizeof(int), &b_r);
    stack_pop(&stack, sizeof(double), &d_r);
    stack_pop(&stack, sizeof(float), &a_r);
    printf("%f,%d,%f\n", a_r, b_r, d_r);
    stack_delete(&stack);
    return 0;
}
