# 一、栈(Stack)
## 1、栈是什么？
一种特殊的线性表，其 只允许在固定的一端进行插入和删除元素操作 。进行数据插入和删除操作的一端称为栈顶，另一端称为栈底。栈中的数据元素遵守后进先出LIFO （ Last In First Out ）的原则。
## 2、栈的操作
使用指针操作是为了直接改变地址存放的值。
~~~C
void stack_init(stack *stack,int size); //初始化栈
bool stack_is_empty(stack *stack); //判断栈是否空，返回bool
bool stack_is_full(stack *stack); //判断栈是否满，返回bool
bool stack_push(stack *stack, void *value, int size); //给栈加元素，栈满返回False
bool stack_pop(stack *stack, void *value, int size); //取出栈元素，栈空返回False
void stack_destroy(stack *stack); //删除栈，释放内存
~~~
## 3、代码实现
### （1）栈底地址大，栈顶地址小，方向从高到低
#### malloc() 分配内存，如果内存池中的可用内存可以满足这个需求，malloc就返回一个指向被分配的内存块起始位置的指针（低）
~~~C
void stack_init(stack *stack,int size){
    stack->base=malloc(size)+size;
    //molloc分配内存给出一个低地址，而栈要求从高地址到低地址，故栈底==低地址+size
    stack->top=stack->base; 
    stack->size=size;
}; 
~~~
### （2）内存记得释放
####free()
~~~C
void stack_destroy(stack *stack){
    free(stack->base-stack->size); //释放内存
};
~~~
### （3）push
#### memcpy()
~~~C
void *memcpy(void *destin, void *source, unsigned n);
//以source指向的地址为起点，将连续的n个字节数据，复制到以destin指向的地址为起点的内存中。
//函数有三个参数，第一个是目标地址，第二个是源地址，第三个是数据长度。
~~~
~~~C
bool stack_push(stack_t *stack, void *value, int sz){
    if (stack->base - stack->top + sz > stack->size) return false; //判断添加元素后是否超出栈大小，超出就返回false
    stack->top-=sz; //重新设置栈顶，地址减小即栈顶增加
    memcpy(stack->top,value,sz); //将value的首地址放入top，base-top即为sz，就是数据的大小
    return true;
}; //给栈加元素，栈满返回False
~~~
###（4）pop
~~~C
bool stack_pop(stack_t *stack, void *value, int sz){
    if (stack->top + sz > stack->base) return false; //判断取出后是否stack->top>stack->base，大于就返回false
    memcpy(value, stack->top, sz); //从栈顶取出value，长度大小base-top=sz，就是value的大小
    stack->top += sz; //重新设置栈顶，地址增加则向栈底移动,让栈顶移动到下一个value的首地址
    return true;
}; //取出栈元素，栈空返回False
~~~
# 二、队列
## 1、队列是什么？
队列只允许在一段插入，在另一端删除，所以只有最早进入对列的才能最先从队列中删除，故队列又称先进先出，即first in first out，简称FIFO。
## 2、队列的操作
使用指针操作是为了直接改变地址存放的值。
~~~C
void queue_inti(queue_t *queue); //初始化对列
bool queue_enqueue(queue_t *queue,float value); //写入元素
bool queue_dequeue(queue_t *queue,float value); //读出元素
bool queue_front(queue_t *queue,float *value); //输出头部元素
bool queue_is_empty(queue_t *queue); // 判断是否空
bool queue_is_full(queue_t *queue); // 判断是否满
~~~
## 3、队列实现
### （1）取余实现循环
我们通过直接取余实现循环。  
#### 情况一：队列已满
此时结果full函数判断，输出false，直接退出enqueue函数，w不再发生改变。
#### 情况二：队列已满后先读出元素，然后读入元素
读出元素后，full函数判断为假，执行后续任务。此时w已超过SQUEUE_MAX_SIZE,防止指针值太大，我们取余后w重新回到1，进行循环。
~~~C
bool queue_enqueue(queue_t *queue,float value){
    if (queue_is_full(queue)) return false; //判断queue是否满了，满了就返回false
    queue->data[queue->w % QUEUE_MAX_SIZE] = value;
    ++queue->w;
    return true;
}; //写入元素
~~~
dequeue同理 若队列已空时，输出元素为0
~~~C
bool queue_dequeue(queue_t *queue,float *value){
    if (queue_is_empty(queue)) return false; //判断queue是否空了，空了就没东西取
    *value=queue->data[queue->r % QUEUE_MAX_SIZE];
    ++queue->r;
    return true;
}; //读出元素
~~~
# 学习记录
## 1、了解了栈和队列的概念，他们的特点，比如FILO、LILO。
## 2、通过定义函数等等一些基本的C语言语法实现功能。如对C语言指针的功能实现对地址中存放元素的改变、通过地址量的改变实现元素FILO、LILO的功能。
## 3、一些特别的处理技巧，比如防止指针量太大，使用取余操作进行循环。
## 4、对数据结构的处理过程有时候和地址中元素的存放要求存在不同。比如栈的存放方向和地址量的增加方向是不同的。
