#include <stdio.h>
#include<stdlib.h>

//刘备采用链式结构写栈

//定义链表结点
struct Node
{
	int data;
	struct Node* next;
};

//定义stack结构体
struct stack
{
	struct Node *stackTop;
	int size;
	
};

//初始化栈
struct stack *creatstack()
{
	struct stack *mystack=(struct stack *)malloc(sizeof(struct stack));//调用malloc分配内存
	mystack->stackTop = NULL;//初始化栈顶
	mystack->size=0;//初始化栈尺寸
	return mystack;
	
}

//初始化结点
struct Node *createnode()
{
	int data;
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;//操作原理和初始化栈大差不差，不赘述
	
}

//入栈函数
void push(struct stack *mystack, int data)
{
	 struct Node*newnode=createnode(data);
	 //入栈
	 newnode->next=mystack->stackTop;//把老栈顶给下一个结点
	 mystack->stackTop=newnode;//新结点值的地址给新的栈顶
	 mystack->size++;//栈的大小扩充
}

//返回栈顶元素，但不移除
int top(struct stack *myStack)
{
	//检查栈是否为空，防御机制
	if(mystack->size==0)
	{
		printf("栈为空，无法获取栈顶元素\n");
		system("pause");
		return mystack->size;
	}
	return mystack->stackTop->data;//返回栈顶值
}


//出栈函数
void pop(struct stack *mystack)
{
	if(mystack->size==0)
	{
		printf("栈为空，无法出栈\n");
		system("pause");
		return mystack->size;
	}
	else
	{
		struct Node *nextnode=mystack->stackTop->next;
		free(mystack->stackTop);//释放栈顶
		mystack->stackTop=nextnode;//新栈顶
		mystack->size--;//缩尺寸
	}
	
}

//判断是否为空
int empty(struct stack *mystack)
{
	if(mystack->size==0)
	{
		printf("空栈");
		return 0;
	}
	return 1;
}

//主函数，开始表演
int main()
{
	struct stack *mystack=createstack();
	push(mystack,1);
	push(mystack,2);
	push(mystack,3);//入栈
	while(empty(mytack))
	{
		printf("%d\t",top(mystack));//返回栈顶
		pop(mystack);//出栈
	}
	printf("\n");
	system("pause");
	return 0;
}