// 循环队列代码实现
#include <stdio.h>
#define MAX_SIZE 5 // 数组长度
// 定义队列结构
typedef struct
{
    int data[MAX_SIZE]; // 保存数据的数组
    int front;          // 保存对头元素位置的指针
    int rear;           // 保存队尾元素位置的指针
} Queue;
// 初始化队列
void initQueue(Queue *q)
{
    q->rear = 0;
    q->front = 0;
}
// 判断队列是否为空
int isEmpty(Queue *q)
{
    return q->front == q->rear;
}
// 判断队列是否已满
int isFull(Queue *q)
{
    return (q->rear + 1) % MAX_SIZE == q->front;
}
// 元素入队
void pop(Queue *q, int val)
{
    if (isFull(q))
    {
        printf("队列已满，无法入队\n");
        return;
    }
    q->rear = (q->rear) % MAX_SIZE;
    q->data[q->rear] = val;
}
// 元素出队
int push(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空，不能出队\n");
        return -1;
    }
    int temp = q->data[q->front];
    q->front = (q->front + 1)%MAX_SIZE;
    return temp;
}
// 获取对头元素
int getFront(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空，不能获取元素\n");
        return 0;
    }
    int temp = q->front + 1;
    return q->data[temp];
}
// 获取队尾元素
int getRear(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空，不能获取元素\n");
        return 0;
    }
    return q->data[q->rear];
}
// 测试函数
void test()
{
    Queue q;
    initQueue(&q);
    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    push(&q, 40);
    // 弹出两元素10,20
    printf("%d", pop(&q));
    printf("%d\n", pop(&q));
    // 再插入两个元素
    push(&q, 50);
    push(&q, 60);
    // 将所有元素出队
    printf("%d", pop(&q));
    printf("%d", pop(&q));
    printf("%d", pop(&q));
    printf("%d", pop(&q));
    printf("%d\n", pop(&q));
    // 提示对空
    printf("%d", pop(&q));return 0;
}
int main()
{
    test();
    return 0;
}