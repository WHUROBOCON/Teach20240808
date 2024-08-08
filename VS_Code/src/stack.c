#include "inc/stack.h"

// 栈的初始化
void stack_init(stack_t *stack,stack_size_t size){
    stack->base = (char*)malloc(size);//分配内存，并将其地址赋给栈底
    stack->top = stack->base;//初始时栈顶等于栈底
    stack->size = size;//赋值栈的大小
}

bool stack_empty(stack_t *stack){
    return stack->top == stack->base;//栈顶等于栈底时，栈为空
}

bool stack_full(stack_t *stack){
    return (stack->base - stack->top) == stack->size;//栈底减去栈顶等于栈的大小时，栈满
}

bool stack_push(stack_t *stack, void *value,stack_size_t size){
    if(stack_full(stack)){
        return false;
    }//栈满时，返回false，不进行入栈操作
    stack->top -= size;//栈顶减去size，即栈顶向下移动size个单位
    memcpy(stack->top,value,size);//将value的内容拷贝到栈顶
    return true;
}

bool stack_pop(stack_t *stack, void *value,stack_size_t size){
    if(stack_empty(stack)){
        return false;
    }//栈空时，返回false，不进行出栈操作
    memcpy(value,stack->top,size);//将栈顶的内容拷贝到value
    stack->top += size;//栈顶向上移动size个单位
    return true;
}

bool stack_top(stack_t *stack, void *value,stack_size_t size){
    if(stack_empty(stack)){
        return false;
    }//栈空时，返回false，不进行取栈顶操作
    memcpy(value,stack->top,size);//将栈顶的内容拷贝到value
    return true;
}

void stack_delete(stack_t *stack){
    free(stack->base - stack->size);//从头开始释放栈的连续内存
}

int main(){
    stack_t stack;
    stack_init(&stack,10);

    float a = 10.f;
    double d = 30.f;
    int b = 20;

    stack_push(&stack,&a,sizeof(float));
    stack_push(&stack,&d,sizeof(double));
    stack_push(&stack,&b,sizeof(int));

    float a2;
    double d2;
    int b2;

    stack_pop(&stack,&b2,sizeof(int));
    stack_pop(&stack,&d2,sizeof(double));
    stack_pop(&stack,&a2,sizeof(float));

    printf("%f %d %lf\n",a2,b2,d2);

    stack_delete(&stack);
    return 0;
}