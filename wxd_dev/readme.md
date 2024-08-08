# 栈，队列，链表（单向和双向）的学习与c语言实现
---

## 1.栈 
### 程序说明
栈是一种线性数据结构，它只允许在一端进行插入和删除操作，另一端称为栈顶，栈顶的元素是最近添加的，栈底的元素是最早添加的。**先进后出**。栈的操作有初始化栈，入栈，出栈，查看栈顶元素，判断栈是否为空，判断栈是否已满。

### 代码实现 
总之就是，利用栈顶栈底指针，在栈的内存空间上进行操作。
**初始化栈**：定义栈大小，分配内存空间，初始化栈顶指针和栈底指针。
~~~c
void stack_init(stack_t *stack,stack_t_size sz){
    stack->top=malloc(sz)+sz;
    stack->base=stack->top;
    stack->size=sz;
};
~~~


**入栈**：从栈顶指针位置开始向栈底指针位置移动sz个字节，将数据拷贝到栈顶指针位置。
~~~c
bool stack_PUSH(stack_t *stack,stack_t_size sz,void *data){
    if(stack_IS_FULL(stack,10)&&stack->base-stack->top<sz)
        return false;
    memcpy(stack->top-sz,data,sz);
    stack->top-=sz;
};
~~~

**出栈：** 从栈顶指针位置开始向栈底指针位置移动sz个字节，将数据拷贝到data指针位置。
~~~c
bool stack_POP(stack_t *stack,stack_t_size sz,void *data){
    if(stack_IS_EMPTY(stack,10)&&stack->base-stack->top<sz)
        return false;
    memcpy(data,stack->top,sz);
    stack->top+=sz;
};
~~~

**查看栈顶元素：** 
~~~c
void *stack_TOP(stack_t *stack,stack_t_size sz){
    if(stack_IS_EMPTY(stack,10)&&stack->base-stack->top<sz)
        return NULL;
    return stack->top;
};
~~~

**判断栈是否为空：**
~~~c
bool stack_IS_EMPTY(stack_t *stack,stack_t_size sz){
    return stack->base-stack->top>=sz;
};
~~~

**判断栈是否已满：**
~~~c
bool stack_IS_FULL(stack_t *stack,stack_t_size sz){
    return stack->base-stack->top<sz;
};
~~~
---
## 2.队列
### 程序说明
队列是一种线性数据结构，它只允许在一端进行插入操作，另一端进行删除操作，队列的头部称为队头，尾部称为队尾，队尾的元素是最近添加的，队头的元素是最早添加的。**先进先出**。队列的操作有初始化队列，入队，出队，查看队头元素，判断队列是否为空，判断队列是否已满。


### 代码实现
队列，用队头和队尾指针来实现。
**初始化队列：**
~~~c
void queue_init(queue_t *queue,queue_t_size sz){
    queue->head=malloc(sz)+sz;
    queue->tail=queue->head;
    queue->size=sz;
};
~~~


**入队：**
~~~c
bool queue_ENQUEUE(queue_t *queue,queue_t_size sz,void *data){
    if(queue_IS_FULL(queue,10)&&queue->tail-queue->head<sz)
        return false;
    memcpy(queue->tail,data,sz);
    queue->tail+=sz;
};

//还有一种简单入队
bool Queue_Put(queue_t *q, double data){
    if(Queue_Full(q))
    return false;
    
    q->data[(q->w++)%q->size]=data;//利用取余运算，实现循环队列，但是程序持续运行，w会不断增大
    return true;
};
~~~

**出队：**  
~~~c
bool queue_DEQUEUE(queue_t *queue,queue_t_size sz,void *data){
    if(queue_IS_EMPTY(queue,10)&&queue->tail-queue->head<sz)
        return false;
    memcpy(data,queue->head,sz);
    queue->head+=sz;
};
~~~


**查看队头元素：**
~~~c
void *queue_HEAD(queue_t *queue,queue_t_size sz){
    if(queue_IS_EMPTY(queue,10)&&queue->tail-queue->head<sz)
        return NULL;
    return queue->head;
};
~~~


**判断队列是否为空：**
~~~c
bool queue_IS_EMPTY(queue_t *queue,queue_t_size sz){
    return queue->tail-queue->head>=sz;
};
~~~


**判断队列是否已满：**
~~~c
bool queue_IS_FULL(queue_t *queue,queue_t_size sz){
    return queue->tail-queue->head<sz;
};
~~~

---
## 3.链表
### 程序说明
链表是一种线性数据结构，它是由一系列节点组成，每个节点都包含数据和一个指向下一个节点的指针。链表的每个节点都有相同的数据类型，可以是整数，字符，结构体等。链表的操作有初始化链表，插入节点，删除节点，查找节点，判断链表是否为空，判断链表是否已满。


### 代码实现
利用含数据块和指针的结构体来作为链表的节点。通过改变指针指向，来实现插入，删除，查找等操作。
**初始化链表：**
~~~c
void list_init(list_t *list,list_t_size sz){
    list->head=malloc(sz);
    list->tail=list->head;
    list->size=sz;
};
~~~


**插入节点：**
~~~c
bool list_INSERT(list_t *list,list_t_size sz,void *data){
    if(list_IS_FULL(list,10)&&list->tail-list->head<sz)
        return false;
    memcpy(list->tail,data,sz);
    list->tail+=sz;
};
~~~


**删除节点：**
~~~c
bool list_DELETE(list_t *list,list_t_size sz,void *data){
    if(list_IS_EMPTY(list,10)&&list->tail-list->head<sz)
        return false;
    memcpy(data,list->head,sz);
    list->head+=sz;
};
~~~


**查找节点：**
~~~c
void *list_FIND(list_t *list,list_t_size sz,void *data){
    list_t_node_t *node=list->head;
    while(node!=NULL){
        if(memcmp(node,data,sz)==0)
            return node;
        node=node->next;
    }
    return NULL;
};
~~~


**判断链表是否为空：**
~~~c
bool list_IS_EMPTY(list_t *list,list_t_size sz){
    return list->tail-list->head>=sz;
};
~~~


**判断链表是否已满：**
~~~c
bool list_IS_FULL(list_t *list,list_t_size sz){
    return list->tail-list->head<sz;
};
~~~

---
## 4.双向链表
### 程序说明
双向链表是一种线性数据结构，它是由一系列节点组成，每个节点都包含数据和两个指向前一个节点和下一个节点的指针。双向链表的每个节点都有相同的数据类型，可以是整数，字符，结构体等。双向链表的操作有初始化双向链表，插入节点，删除节点，查找节点，判断双向链表是否为空，判断双向链表是否已满。


### 代码实现（和单向类似，只需修改指针的指向方向即可）
---
## 5.学习记录（初学很累人）
- 栈：先进后出，栈顶元素是最近添加的，栈底元素是最早添加的。栈的操作有初始化栈，入栈，出栈，查看栈顶元素，判断栈是否为空，判断栈是否已满。
- 队列：先进先出，队头元素是最早添加的，队尾元素是最近添加的。队列的操作有初始化队列，入队，出队，查看队头元素，判断队列是否为空，判断队列是否已满。
- 链表：链表是一种线性数据结构，它是由一系列节点组成，每个节点都包含数据和一个指向下一个节点的指针。链表的每个节点都有相同的数据类型，可以是整数，字符，结构体等。链表的操作有初始化链表，插入节点，删除节点，查找节点，判断链表是否为空，判断链表是否已满。
- 双向链表：双向链表是一种线性数据结构，它是由一系列节点组成，每个节点都包含数据和两个指向前一个节点和下一个节点的指针。双向链表的每个节点都有相同的数据类型，可以是整数，字符，结构体等。双向链表的操作有初始化双向链表，插入节点，删除节点，查找节点，判断双向链表是否为空，判断双向链表是否已满。
### 有几个函数很有用
malloc()：分配内存，返回一个指针，用来存放数据。一般用sizeof（数据类型）来计算需要分配的内存大小。
free()：释放内存，释放之前malloc()分配的内存。
memcpy(a，b，n)：拷贝内存，将一个内存块拷贝到另一个内存块。
a：源地址，b：目的地址，n：拷贝的字节数（用sizeof（数据类型）来计算）。