#include"string.h"
#include"inc/stack.h"
#include"stdlib.h"
#include"stdio.h"
//由于结构体中定义的是char类型的指针，所以对top以及base指针的加1减1都只改变一个字节
//栈遵循后进先出的原则
void Stack_Init(stack *stack,stack_size size)          
{
    stack->base = ((char *)malloc(size))+size;            //malloc 函数在内存的动态存储区中分配一个长度为size的连续空间并返回起始地址。由此求得栈底的地址，ps；栈底到栈顶的地址是逐渐减小的。            
    stack->top=stack->base;                               //初始时两者地址相等
    stack->size=size;                             
}
bool Stack_Is_Full(stack *stack)
{
    return (stack->top<=(stack->base-stack->size));     //当栈满时，top地址比base地址小size
}
bool Stack_Is_Empty(stack *stack)
{
    return (stack->top==stack->base);                     //当栈空时，栈顶与栈底地址相等
}
bool Stack_Pop(stack *stack, void *value,stack_size sz)
{
    if (Stack_Is_Empty(stack)) return false;
    memcpy(value,stack->top,sz);                        
    stack->top+=sz;                                       //元素出栈后，top地址增大，从而移除栈顶元素
    return true;
}
bool Stack_Push(stack *stack, void *value,stack_size sz)
{
    if (Stack_Is_Full(stack)) return false;
    stack->top-=sz;                                      //先移动top的地址再执行入栈操作
    memcpy(stack->top,value,sz); 
    return true;
}
bool Stack_Top(stack *stack,void *value,stack_size sz)
{
    if (Stack_Is_Empty(stack)) return false;
    memcpy(value,stack->top,sz);
    return true;
}
void Stack_Delete(stack *stack)
{
    free(stack->base - stack->size);
}
void main()
{  
    stack stack;                            //定义结构体
    int a[5]={1,2,3,4,5};                   //定义数组，数组元素后续将被存入栈中
    Stack_Init(&stack,20);                  //初始化
    for (int i = 0; i < 5; i++)             //循环，利用Stack_Push函数将数组元素存入栈内
    { 
      Stack_Push(&stack,&a[i],sizeof(int));
    }


   for (int j = 0; j< 5; j++)               //循环，利用函数Stack_Pop导出数组元素
    { int n;
       Stack_Pop(&stack,&n,sizeof(n));
       printf("%d\n",n);
    }
    Stack_Delete(&stack);                   //释放空间
}
