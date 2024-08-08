#include "../inc/stack.h"//引用头文件


void stack_init(stack_t *stack,stack_t_size sz){//定义初始化栈函数
    stack->top=malloc(sz)+sz;
    stack->base=stack->top;
    stack->size=sz;
};
bool stack_IS_EMPTY(stack_t *stack,stack_t_size sz){return stack->top==stack->base;};//定义判断栈是否为空的函数
bool stack_IS_FULL(stack_t *stack,stack_t_size sz){return stack->base-stack->top==sz;};//定义判断栈是否已满的函数
bool stack_PUSH(stack_t *stack,stack_t_size sz,void *data){//定义进栈函数
    if(stack_IS_FULL(stack,10)&&stack->base-stack->top<sz)
        return false;
    memcpy(stack->top-sz,data,sz);
    stack->top-=sz;
};
bool stack_POP(stack_t *stack,stack_t_size sz,void *data){//定义出栈函数
    if(stack_IS_EMPTY(stack,10)&&stack->base-stack->top<sz)
        return false;
    memcpy(data,stack->top,sz);//将出栈的数据存入data指针指向的地址中
    stack->top+=sz;
};
void stack_delete(stack_t *stack,stack_t_size sz){//定义清理栈函数
    free(stack->base-stack->size);
    stack->top=stack->base;
}

//调用上面定义的函数实现将data中数据存入栈中，再从栈中取出数据并打印出来
int main(){
   
    typedef struct Data{
        int a;
        double b;
        char c;
    }data;
    data data_1={1,2.f,'3'};
    stack_t stack;
    stack_init(&stack,10);
    stack_PUSH(&stack,sizeof(data_1.a),&data_1.a);
    stack_PUSH(&stack,sizeof(data_1.b),&data_1.b);
    stack_PUSH(&stack,sizeof(data_1.c),&data_1.c);
    int d;
    double e;
    char f;
    stack_POP(&stack,sizeof(f),&f);

    stack_POP(&stack,sizeof(e),&e);
    stack_POP(&stack,sizeof(d),&d);
    printf("%d %1.lf %c\n",d,e,f);
    stack_delete(&stack,10);
    if(stack_IS_EMPTY(&stack,10))
    printf("stack is empty\n");
}
