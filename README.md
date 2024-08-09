# Welcome to WHUROBOCON!
#include <stdio.h>
#define MAX_SIZE 100
typedef struct
{
    int data[MAX_SIZE]; // 保存数据的数组
    int top;// 定义保存栈顶元素下标的指针
} Stack;
// 初始化栈
void initStack(Stack *stack)
{ 
    stack->top = -1;// 当栈空的时候，栈顶指针保存-1
}
// 判栈站是否为空
int isEmpyt(Stack*stack){
    return stack->top == -1;
}
//弹出栈元素
int pop(Stack *stack)
{
    
    if (isEmpyt(stack))
    {
        printf("栈为空，无法弹出元素\n");
        return 0;
    }// 如果栈空，是不能弹出元素的，提醒栈空
    int val=stack->data[stack->top];
    stack->top--;
    return val;
}
//判断栈是否满
int isFull(Stack*stack){
    return stack->top == MAX_SIZE-1;
}
// 栈插入元素
void push(Stack*stack,int val){
    if (isFull(stack))
    {
        printf("栈满了\n");
        return;
        }//如果栈满了就不能插入元素了
        stack->top++;
        stack->data[stack->top] = val;
}
//获取栈顶元素的值
int top(Stack*stack){
 if (isEmpyt(stack))
    {
        printf("栈为空，无法弹出元素\n");
        return 0;
    }// 如果栈空，是不能弹出元素的，提醒栈空
    return stack->data[stack->top];
}
int main(int argc, char const *argv[])
{
    //定义一个栈
    Stack s1;
    initStack(&s1);
    push (&s1,10);
    push (&s1,20);
    push (&s1,30);
    push (&s1,40);
    push (&s1,50);
    int topval;
    for (int i = 0; i < 5; i++){
        topval=top(&s1);
        printf("%d\n",topval);
        pop(&s1);
    }
    return 0;
}

