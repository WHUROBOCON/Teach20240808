#include <stdio.h>
#include <stdbool.h>

#define QUEUE_CAPACITY 10 // 定义队列的最大容量为10

typedef struct {
    float elements[QUEUE_CAPACITY]; // 用于存储队列元素的数组
    int head;    //定义头尾索引与队列大小
    int tail;    
    int size;    
} CircularQueue;

// 初始化队列，使各索引与队列大小均为零
void initialize_queue(CircularQueue *q) {
    q->head = 0;      
    q->tail = 0;      
    q->size = 0;      
}

// 将元素压入队列
bool enqueue(CircularQueue *q, float value) {
    if (q->size == QUEUE_CAPACITY) {
        return false; // 如果队列已满，无法添加元素
    }
    q->elements[q->tail] = value; // 将值存储在队列的尾部位置
    q->tail = (q->tail + 1) % QUEUE_CAPACITY; // 更新尾部索引，确保其在有效范围内
    q->size++; //元素数量增加
    return true;  
}

// 从队列中移除元素
bool dequeue(CircularQueue *q, float *value) {
    if (q->size == 0) {
        return false; // 如果队列为空，无法移除元素
    }
    *value = q->elements[q->head]; // 从队列前端读取值
    q->head = (q->head + 1) % QUEUE_CAPACITY; // 更新前端索引，确保其在有效范围内
    q->size--; // 元素数量减少
    return true;  
}

// 获取队列前端的元素但不移除
bool peek_front(CircularQueue *q, float *value) {
    if (q->size == 0) {
        return false; // 如果队列为空，无法获取元素
    }
    *value = q->elements[q->head]; // 从队列前端读取值
    return true;  
}

// 检查队列是否为空
bool is_queue_empty(CircularQueue *q) {
    return q->size == 0; // 条件为元素数量为0 
}

// 检查队列是否为满
bool is_queue_full(CircularQueue *q) {
    return q->size == QUEUE_CAPACITY; // 条件为元素数量等于队列最大容量 
}

// 主函数
int main() {
    CircularQueue queue; // 声明并初始化
    initialize_queue(&queue); 

    // 向队列压入10个浮点值
    for (int i = 0; i < 10; ++i) {
        enqueue(&queue, (float)i);
    }

    // 从队列中移除并打印10个浮点值
    float value;  
    while (dequeue(&queue, &value)) {
        printf("%f\n", value);  
    }

    return 0;  
}
