#include "../inc/queue.h"

void queue_init(queue_t *queue)
{
    queue->r = queue->w = 0;
} // 初始化队列
bool queue_enqueue(queue_t *queue, float value)
{
    if (queue_is_full(queue))
        return false;              // 判断队列是否已满
    queue->data[queue->w] = value; // 队列未满，将数据value写入队列
    ++queue->w;                    // 改变队尾指针
    queue->w %= QUEUE_MAX_SIZE;    // 防止超出范围
    return true;
}
bool queue_dequeue(queue_t *queue, float *value)
{
    if (queue_is_empty(queue))
        return false;               // 判断是否有数据
    *value = queue->data[queue->r]; // 读取排在最前面的数据
    ++queue->r;                     // 读完数据后，使队头指针向后移
    queue->r %= QUEUE_MAX_SIZE;     // 防止超出范围
    return true;
} // 出队是对数组的第一个元素进行删除操作

bool queue_front(queue_t *queue, float *value)
{
    if (queue_is_empty(queue))
        return false;               // 判断是否有数据
    *value = queue->data[queue->r]; // 排在最前面的数据读取
} // 读取第一个数据但不移除
bool queue_is_empty(queue_t *queue)
{
    return queue->w == queue->r;
}
bool queue_is_full(queue_t *queue)
{
    int sz = queue->w - queue->r;
    sz = sz >= 0 ? sz : sz + QUEUE_MAX_SIZE; // 如果sz为正，代表队列的个数，如果sz为负，说明队列满员过，w指针在r指针的下面
    return sz == QUEUE_MAX_SIZE;
}

int main()
{
    queue_t queue;
    queue_init(&queue);

    for (int i = 0; i < 10; ++i)
    {
        queue_enqueue(&queue, (float)i);
    }
    for (int i = 0; i < 10; ++i)
    {
        float temp;
        queue_dequeue(&queue, &temp);
        printf("%f\n", temp);
    }
    return 0;
}
