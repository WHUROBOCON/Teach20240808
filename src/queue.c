#include "inc/queue.h"

void queue_init(Queue_t *queue, queue_size_t size)
{
    // queue_size_t sizemax = size+1;
    queue->front = malloc(size);        // malloc返回的是指向堆内存的指针，所以要加上size才能指向队头
    printf("front:%p\n", queue->front); // 打印队头指针
    queue->rear = queue->front;
    queue->size = size;
}

bool queue_push(Queue_t *queue, void *value, queue_size_t size) // 入队
{
    if (queue_is_full(queue))
    {
        printf("the queue is full");
        return false;
    }
    memcpy(queue->rear, value, size);
    // memcpy函数的功能是从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中
    queue->rear += size; // 队尾指针后移
    return true;
}
bool queue_pop(Queue_t *queue, void *value, queue_size_t size) // 出队
{
    if (queue_is_empty(queue))
        return false;
    memcpy(value, queue->front, size); // 释放队头元素
    queue->front += size;              // 队头指针后移
    return true;
}
bool queue_clear(Queue_t *queue) // 清空队列
{
    if (queue_is_empty(queue))
        return false;
    while (queue->front != queue->rear)
    {
        free(queue->front); // 释放队头元素
        queue->front--;     // 队头指针后移
    }
    return true;
}
bool queue_is_empty(Queue_t *queue) // 判断队列是否为空
{
    return queue->front == queue->rear; // 队空时front指向队头
}
bool queue_is_full(Queue_t *queue) // 判断队列是否满
{
    int size = queue->front - queue->rear;       // 计算队列元素个数
    size = size > 0 ? size : size + queue->size; // 队列元素个数
    return queue->rear == queue->size;           // 队满时rear指向队尾
}
void queue_destroy(Queue_t *queue) // 销毁队列
{
    free(queue->front);
    free(queue->rear);
}

bool queue_get_front(Queue_t *queue, void *value, queue_size_t size) // 获取队头元素
{
    if (queue_is_empty(queue))
        return false;
    memcpy(value, queue->front, size); // 将队头元素拷贝到value中
    return true;
}

int main()
{
    Queue_t queue;
    queue_size_t size = 20;
    queue_init(&queue, size);
    float a = 10.f;
    double d = 30.f;
    int b = 20;
    printf("first %f %lf %d\n", a, d, b);
    queue_push(&queue, &a, sizeof(a));
    queue_push(&queue, &d, sizeof(d));
    queue_push(&queue, &b, sizeof(b));

    float a1;
    double d1;
    int b1;

    queue_get_front(&queue, &a1, sizeof(a1));
    printf("front %f\n", a1);

    queue_pop(&queue, &a1, sizeof(a1));
    queue_pop(&queue, &d1, sizeof(d1));
    queue_pop(&queue, &b1, sizeof(b1));
    printf("%f %lf %d\n", a1, d1, b1);
    queue_clear(&queue);
    return 0;
}