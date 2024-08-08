#include "..\inc\stack.h"
#include<stdio.h>

void stack_init(stack_t *stack,int size){
    stack->base=malloc(size)+size; //注意低地址和栈底层的关系，反
    stack->top=stack->base; //一开始，栈顶=栈底
    stack->size=size;
}; 

bool stack_is_empty(stack_t *stack){
    return (stack->top==stack->base);
}; //判断栈是否空，即栈空时即top==base 栈空时返回true

bool stack_is_full(stack_t *stack){
    return ((stack->base-stack->size)==stack->top);
}; //判断栈是否满，返回bool，栈满时返回true

bool stack_push(stack_t *stack, void *value, int sz){
    if (stack->base - stack->top + sz > stack->size) return false; //判断添加元素后是否超出栈大小，超出就返回false
    stack->top-=sz; //重新设置栈顶，地址减小即栈顶增加
    memcpy(stack->top,value,sz); //将value的首地址放入top，base-top即为sz，就是数据的大小
    return true;
}; //给栈加元素，栈满返回False

bool stack_pop(stack_t *stack, void *value, int sz){
    if (stack->top + sz > stack->base) return false; //判断取出后是否stack->top>stack->base，大于就返回false
    memcpy(value, stack->top, sz); //从栈顶取出value，长度大小base-top=sz，就是value的大小
    stack->top += sz; //重新设置栈顶，地址增加则向栈底移动,让栈顶移动到下一个value的首地址
    return true;
}; //取出栈元素，栈空返回False

void stack_destroy(stack_t *stack){
    free(stack->base-stack->size); //释放内存，free()与malloc()对应
};

int main(int argc, char const *argv[])
{
    stack_t stack; //定义结构体
    stack_init(&stack,20); //初始化栈

    float a=10.f;
    double b=20.f;
    int c=30;

    stack_push(&stack,&a,sizeof(float)); //4 Byte
    stack_push(&stack,&b,sizeof(double)); //8 Byte
    stack_push(&stack,&c,sizeof(int)); //4 Byte
  
    float a_r;
    double b_r;
    int c_r;

    stack_pop(&stack,&c_r,sizeof(int)); //与输入反着来，遵从LIFO
    stack_pop(&stack,&b_r,sizeof(double));
    stack_pop(&stack,&a_r,sizeof(float));
    
    printf("%f,%lf,%d\n",a_r,b_r,c_r);

    stack_destroy(&stack);

    return 0;
}

